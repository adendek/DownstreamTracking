void fitMassKs(){
    
  gROOT->ProcessLine(".x lhcbStyle.C");
  
  
  TFile* file = TFile::Open("KsPiPi2016Down.root");
  TTree* tree = (TTree*)file->Get("KsPiPiTuple/DecayTree");

  //TFile* file = TFile::Open("BJpsiKs2016DownwithOld.root");
  //TFile* file = TFile::Open("BJpsiKs2016DownwithMLP.root");
  //TTree* tree = (TTree*)file->Get("BJpsiKsTuple/DecayTree");

  
   
  TFile* dummy = new TFile("dummy.root","RECREATE");
  TTree* tree2 = tree->CopyTree("piminus_TRACK_Type == 5 && piplus_TRACK_Type == 5");
  

  // -- Parameters for CB
  RooRealVar KSmass("KS0_M", "mass", 450.0, 550.0);
  RooRealVar meanKS("meanKS", "meanKS", 497.0, 470.0, 530.0);
  RooRealVar sigma("sigma","sigma",10.0, 2.0, 20.0);
  RooGaussian gauss("gauss","gauss", KSmass, meanKS,sigma);
  
  RooRealVar tau("tau","tau", -0.0001, -0.01, 0.0);
  RooExponential exp("exp","exp", KSmass, tau);
  
  RooRealVar coeff("coeff","coeff", 0.0, -1.0, 1.0);
  RooChebychev bg("bg","bg", KSmass, RooArgList(coeff));
  

  RooRealVar signalYield("signalYield","signalYield", 100.0, 10.0, 50000.0);
  RooRealVar bgYield("bgYield","bgYield", 100.0, 10.0, 50000.0);
  RooAddPdf massPdf("massPdf","pdf for mass", RooArgList(gauss, bg), RooArgList(signalYield, bgYield));
  
  RooRealVar piminusPT("piminus_PT", "pi- pt", 50.0, 10.0, 50000.0);
  RooRealVar piplusPT("piplus_PT", "pi+ pt", 50.0, 10.0, 50000.0);
  RooRealVar piminusP("piminus_P", "pi- p", 50.0, 10.0, 500000.0);
  RooRealVar piplusP("piplus_P", "pi+ p", 50.0, 10.0, 500000.0);
  RooRealVar piminusEta("piminus_eta", "pi- eta", 2.0, 1.7, 5.5);
  RooRealVar piplusEta("piplus_eta", "p+ eta", 2.0, 1.7, 5.5);
  RooRealVar piminusPhi("piminus_phi", "pi- phi", 0.0, -3.15, 3.15);
  RooRealVar piplusPhi("piplus_phi", "p+ phi", 0.0, -3.15, 3.15);

  RooRealVar piminusGP("piminus_TRACK_GhostProb", "ghost prob", 0.1, 0.0, 1.0);
  RooRealVar piplusGP("piplus_TRACK_GhostProb", "ghost prob", 0.1, 0.0, 1.0);

  RooRealVar VtxChi2("KS0_ENDVERTEX_CHI2","Vtx chi2", 1.0, 0.0, 100.0);
  

  RooDataSet ds("ds","ds", RooArgSet(KSmass, piminusPT, piplusPT, piminusP, piplusP, piminusEta, piplusEta, piminusPhi, piplusPhi), RooFit::Import(*tree2), RooFit::Cut("piplus_PT > 50 && piminus_PT > 50 && piminus_P > 2000 && piplus_P > 2000"));
  
  RooPlot* plot = KSmass.frame();
  ds.plotOn( plot );
  massPdf.fitTo( ds );
  massPdf.plotOn( plot );
  
  plot->Draw();
  
  //return;
  

  RooRealVar sw("signalYield_sw","sWeight for signal yield", 0.0, -50.0, 50.0);
  RooStats::SPlot* sData = new RooStats::SPlot("sData","An SPlot", ds, &massPdf, RooArgList(signalYield,bgYield)); 

  ds.Print();
  

  RooDataSet dsS(ds.GetName(),ds.GetTitle(),
                 RooArgSet(piminusPT, piplusPT, piminusP, piplusP, piminusEta, piplusEta, piminusPhi, piplusPhi, sw), 
                 RooFit::Import(ds));
  //RooFit::WeightVar("signalYield_sw")) ;
  
  TFile* outFile = new TFile("test.root","RECREATE");
  
  TH1D* histoPT = new TH1D("histoPT","histoPT", 25, 0, 5000.0);
  TH1D* histoP = new TH1D("histoP","histoP", 25, 0, 50000.0);
  TH1D* histoEta = new TH1D("histoEta","histoEta", 25, 1.7, 5.5);
  TH1D* histoPhi = new TH1D("histoPhi","histoPhi", 25, -3.14, 3.141);
  
  for(int i = 0; i < dsS.numEntries(); ++i){
    double pt = dsS.get(i)->getRealValue("piminus_PT");
    double p = dsS.get(i)->getRealValue("piminus_P");
    double phi = dsS.get(i)->getRealValue("piminus_phi");
    double eta = dsS.get(i)->getRealValue("piminus_eta");
    
    double w = dsS.get(i)->getRealValue("signalYield_sw");
    histoPT->Fill(pt,w);
    histoP->Fill(p,w);
    histoPhi->Fill(phi,w);
    histoEta->Fill(eta,w);
    
  }
  
  outFile->Write();
  outFile->Close();
  

  
  TCanvas* c = new TCanvas();
  histoPT->Draw("e");
  c = new TCanvas();
  histoP->Draw("e");
  c = new TCanvas();
  histoPhi->Draw("e");
  c = new TCanvas();
  histoEta->Draw("e");
  
  return;
  

  
}
   
