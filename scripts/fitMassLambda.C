void fitMassLambda(){
    
  gROOT->ProcessLine(".x ~/style/lhcbStyle4.C");

  
  //TFile* file = TFile::Open("/eos/lhcb/user/d/decianm/KsPiPi2016DownNewPatLLT.root");
  //TFile* file = TFile::Open("/eos/lhcb/user/d/decianm/KsPiPi2016DownOldPatLLT.root");
  //TFile* file = TFile::Open("/eos/lhcb/user/d/decianm/KsPiPi2016DownNewPatLLTHighThres2.root");
  //TFile* file = TFile::Open("/eos/lhcb/user/d/decianm/KsPiPi2016DownNewPatLLTHighThres2MVA.root");
  //TFile* file = TFile::Open("/eos/lhcb/user/d/decianm/KsPiPi2016DownNewPatLLTHighThres2MVAv03.root");
  //TFile* file = TFile::Open("/eos/lhcb/user/d/decianm/KsPiPi2016Downv6Simple.root");
  //TFile* file = TFile::Open("/eos/lhcb/user/d/decianm/KsPiPi2016Downv7Simple.root");
  //TFile* file = TFile::Open("/eos/lhcb/user/d/decianm/DownTestOldPatLLT.root");
  //TFile* file = TFile::Open("/eos/lhcb/user/d/decianm/DownTestNewPatLLT.root");
  TFile* file = TFile::Open("/eos/lhcb/user/d/decianm/DownTestMLPPatLLT.root");
  //TFile* file = TFile::Open("KsPiPi2016Down.root");
  TTree* tree = (TTree*)file->Get("LambdaPPiTuple/DecayTree");
  TFile* dummy = new TFile("dummy.root","RECREATE");
  TTree* tree2 = tree->CopyTree("piminus_TRACK_Type == 5 && pplus_TRACK_Type == 5");
  

  // -- Parameters for CB
  RooRealVar Lambdamass("Lambda0_M", "mass", 1090.0, 1140.0);
  RooRealVar meanLambda("meanLambda", "mean Lambda", 1115.0, 1110.0, 1120.0);
  RooRealVar sigma("sigma","sigma",10.0, 1.0, 20.0);
  RooGaussian gauss("gauss","gauss", Lambdamass, meanLambda,sigma);
  
  RooRealVar tau("tau","tau", -0.0001, -0.01, 0.0);
  RooExponential exp("exp","exp", Lambdamass, tau);
  
  RooRealVar coeff("coeff","coeff", 0.0, -1.0, 1.0);
  RooChebychev bg("bg","bg", Lambdamass, RooArgList(coeff));
  

  RooRealVar signalYield("signalYield","signalYield", 100.0, 10.0, 50000.0);
  RooRealVar bgYield("bgYield","bgYield", 100.0, 10.0, 50000.0);
  RooAddPdf massPdf("massPdf","pdf for mass", RooArgList(gauss, bg), RooArgList(signalYield, bgYield));
  
  RooRealVar piminusPT("piminus_PT", "piminus PT", 50.0, 0.0, 100000.0);
  RooRealVar pplusPT("pplus_PT", "pplus PT", 50.0, 0.0, 100000.0);
  
  RooRealVar piminusP("piminus_P", "pi- p", 50.0, 50.0, 60000.0);
  RooRealVar pplusP("pplus_P", "p+ p", 50.0, 50.0, 60000.0);
  RooRealVar piminusEta("piminus_eta", "pi- eta", 2.0, 1.7, 5.5);
  RooRealVar pplusEta("pplus_eta", "p+ eta", 2.0, 1.7, 5.5);
  RooRealVar piminusPhi("piminus_phi", "pi- phi", 0.0, -3.15, 3.15);
  RooRealVar pplusPhi("pplus_phi", "p+ phi", 0.0, -3.15, 3.15);


  RooRealVar piminusGP("piminus_TRACK_GhostProb", "ghost prob", 0.1, 0.0, 1.0);
  RooRealVar pplusGP("piplus_TRACK_GhostProb", "ghost prob", 0.1, 0.0, 1.0);

  RooRealVar fd("Lambda0_FD_OWNPV","lambda fd", 0.0, 0.0, 3000.0);
  
  RooDataSet ds("ds","ds", RooArgSet(Lambdamass, piminusPT, pplusPT, piminusP, pplusP, piminusEta, pplusEta, fd, pplusPhi), RooFit::Import(*tree2), RooFit::Cut("pplus_PT > 100 && piminus_PT > 100 && pplus_P > 2000 && piminus_P > 2000"));
  
  RooPlot* plot = Lambdamass.frame();
  ds.plotOn( plot );
  massPdf.fitTo( ds );
  massPdf.plotOn( plot );
  
  plot->Draw();
  
  RooRealVar sw("signalYield_sw","sWeight for signal yield", 0.0, -50.0, 50.0);
  RooStats::SPlot* sData = new RooStats::SPlot("sData","An SPlot", ds, &massPdf, RooArgList(signalYield,bgYield)); 

  ds.Print();
  

  RooDataSet dsS(ds.GetName(),ds.GetTitle(),
                 RooArgSet(piminusPT, pplusPT, piminusP, pplusP, piminusEta, pplusEta, pplusPhi, sw, fd), 
                 RooFit::Import(ds));
  //RooFit::WeightVar("signalYield_sw")) ;
  
  TFile* outFile = new TFile("test.root","RECREATE");
  
  TH1D* histoPT = new TH1D("histoPT","histoPT", 25, 0, 5000.0);
  TH1D* histoP = new TH1D("histoP","histoP", 25, 0, 50000.0);
  TH1D* histoEta = new TH1D("histoEta","histoEta", 25, 1.7, 5.5);
  TH1D* histoPhi = new TH1D("histoPhi","histoPhi", 25, -3.14, 3.141);
  TH1D* histoFD = new TH1D("histoFD","histoFD", 25, 0.0, 3000.0);
  
  for(int i = 0; i < dsS.numEntries(); ++i){
    double pt = dsS.get(i)->getRealValue("pplus_PT");
    double p = dsS.get(i)->getRealValue("pplus_P");
    double phi = dsS.get(i)->getRealValue("pplus_phi");
    double eta = dsS.get(i)->getRealValue("pplus_eta");
    double fd =  dsS.get(i)->getRealValue("Lambda0_FD_OWNPV");

    double w = dsS.get(i)->getRealValue("signalYield_sw");
    histoPT->Fill(pt,w);
    histoP->Fill(p,w);
    histoPhi->Fill(phi,w);
    histoEta->Fill(eta,w);
    histoFD->Fill(fd,w);
  }
  
  outFile->Write();
  outFile->Close();
  





  return;
  

  
}
   
