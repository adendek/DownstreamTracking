#include"ReadMLP_ReLu.h"

void ReadMLP_ReLu::Initialize()
{
   // build network structure
   fLayers = 3;
   fLayerSize[0] = 12; fWeights[0] = new double[12]; 
   fLayerSize[1] = 17; fWeights[1] = new double[17]; 
   fLayerSize[2] = 1; fWeights[2] = new double[1]; 
   // weight matrix from layer 0 to 1
   fWeightMatrix0to1[0][0] = -1.38948585449523;
   fWeightMatrix0to1[1][0] = 0.016244237455631;
   fWeightMatrix0to1[2][0] = 1.03169538406978;
   fWeightMatrix0to1[3][0] = -0.294563057357386;
   fWeightMatrix0to1[4][0] = 1.25568651910379;
   fWeightMatrix0to1[5][0] = 0.258202878197321;
   fWeightMatrix0to1[6][0] = -2.39228290205984;
   fWeightMatrix0to1[7][0] = 2.5322369009564;
   fWeightMatrix0to1[8][0] = -0.285168469022583;
   fWeightMatrix0to1[9][0] = 0.110462885267344;
   fWeightMatrix0to1[10][0] = -0.212499269217813;
   fWeightMatrix0to1[11][0] = 1.07550689204719;
   fWeightMatrix0to1[12][0] = 0.956327797916958;
   fWeightMatrix0to1[13][0] = -6.15959256609371;
   fWeightMatrix0to1[14][0] = -0.384205025753522;
   fWeightMatrix0to1[15][0] = -0.45324272244601;
   fWeightMatrix0to1[0][1] = -5.14881683186073;
   fWeightMatrix0to1[1][1] = 2.34950751357905;
   fWeightMatrix0to1[2][1] = 5.03022440741274;
   fWeightMatrix0to1[3][1] = 5.57055065555874;
   fWeightMatrix0to1[4][1] = -1.62799185780698;
   fWeightMatrix0to1[5][1] = -1.29022801013023;
   fWeightMatrix0to1[6][1] = 1.0263428199484;
   fWeightMatrix0to1[7][1] = 0.548428262768599;
   fWeightMatrix0to1[8][1] = -0.44449990227098;
   fWeightMatrix0to1[9][1] = -12.2466544054126;
   fWeightMatrix0to1[10][1] = 3.50758523659996;
   fWeightMatrix0to1[11][1] = -0.425769580664958;
   fWeightMatrix0to1[12][1] = -1.9943661268676;
   fWeightMatrix0to1[13][1] = 0.143912897691372;
   fWeightMatrix0to1[14][1] = 5.68824031920684;
   fWeightMatrix0to1[15][1] = 1.21674591688935;
   fWeightMatrix0to1[0][2] = 2.39557575861006;
   fWeightMatrix0to1[1][2] = 0.295039394817569;
   fWeightMatrix0to1[2][2] = -0.865324023493578;
   fWeightMatrix0to1[3][2] = -2.49441458286479;
   fWeightMatrix0to1[4][2] = -5.75479788531942;
   fWeightMatrix0to1[5][2] = 5.01351395127237;
   fWeightMatrix0to1[6][2] = -3.48842566039683;
   fWeightMatrix0to1[7][2] = 1.22670888198549;
   fWeightMatrix0to1[8][2] = 7.48040516751325;
   fWeightMatrix0to1[9][2] = -2.34850251041644;
   fWeightMatrix0to1[10][2] = 1.7059933422977;
   fWeightMatrix0to1[11][2] = 6.31491269052301;
   fWeightMatrix0to1[12][2] = -19.7542744415585;
   fWeightMatrix0to1[13][2] = -8.40231458838225;
   fWeightMatrix0to1[14][2] = -4.38658619350088;
   fWeightMatrix0to1[15][2] = 0.796392476012005;
   fWeightMatrix0to1[0][3] = 0.0976274019250628;
   fWeightMatrix0to1[1][3] = 3.2626676397485;
   fWeightMatrix0to1[2][3] = 9.3231566606451;
   fWeightMatrix0to1[3][3] = 1.83223805743351;
   fWeightMatrix0to1[4][3] = -3.14950016836502;
   fWeightMatrix0to1[5][3] = 6.02764650665777;
   fWeightMatrix0to1[6][3] = -0.61668679660543;
   fWeightMatrix0to1[7][3] = -0.715990957064703;
   fWeightMatrix0to1[8][3] = 1.24302384189622;
   fWeightMatrix0to1[9][3] = 4.52581571932789;
   fWeightMatrix0to1[10][3] = 0.95727958669001;
   fWeightMatrix0to1[11][3] = -0.151580171856968;
   fWeightMatrix0to1[12][3] = 1.33455123695703;
   fWeightMatrix0to1[13][3] = 3.14814898150057;
   fWeightMatrix0to1[14][3] = -2.4195153371482;
   fWeightMatrix0to1[15][3] = 0.781112730208833;
   fWeightMatrix0to1[0][4] = 1.05724274657971;
   fWeightMatrix0to1[1][4] = -4.44293722151036;
   fWeightMatrix0to1[2][4] = 1.70117915211907;
   fWeightMatrix0to1[3][4] = 0.680636448836296;
   fWeightMatrix0to1[4][4] = 1.28198449731607;
   fWeightMatrix0to1[5][4] = 1.89603191360443;
   fWeightMatrix0to1[6][4] = -8.81128903822172;
   fWeightMatrix0to1[7][4] = -1.04783708906342;
   fWeightMatrix0to1[8][4] = 2.17385331965323;
   fWeightMatrix0to1[9][4] = 3.17472678266211;
   fWeightMatrix0to1[10][4] = 2.65327257404195;
   fWeightMatrix0to1[11][4] = -0.358643774379114;
   fWeightMatrix0to1[12][4] = 2.00562751183419;
   fWeightMatrix0to1[13][4] = 1.18596015162416;
   fWeightMatrix0to1[14][4] = -0.828841557166553;
   fWeightMatrix0to1[15][4] = 5.35765018288143;
   fWeightMatrix0to1[0][5] = 0.200950572913996;
   fWeightMatrix0to1[1][5] = 0.951380668183885;
   fWeightMatrix0to1[2][5] = -1.134274143796;
   fWeightMatrix0to1[3][5] = -4.70077077828047;
   fWeightMatrix0to1[4][5] = -0.43042286289344;
   fWeightMatrix0to1[5][5] = 0.270837774736878;
   fWeightMatrix0to1[6][5] = 0.671930179784451;
   fWeightMatrix0to1[7][5] = -1.45372527753698;
   fWeightMatrix0to1[8][5] = -5.54433852403292;
   fWeightMatrix0to1[9][5] = -1.2172071700386;
   fWeightMatrix0to1[10][5] = -0.157619303145234;
   fWeightMatrix0to1[11][5] = -2.27141067807198;
   fWeightMatrix0to1[12][5] = 1.4728232654346;
   fWeightMatrix0to1[13][5] = 2.81732793478883;
   fWeightMatrix0to1[14][5] = -4.80639339993523;
   fWeightMatrix0to1[15][5] = 0.465974033564316;
   fWeightMatrix0to1[0][6] = -2.42383683118062;
   fWeightMatrix0to1[1][6] = -1.64989458729545;
   fWeightMatrix0to1[2][6] = -0.993507602527374;
   fWeightMatrix0to1[3][6] = 1.05005484719188;
   fWeightMatrix0to1[4][6] = 0.503326700292205;
   fWeightMatrix0to1[5][6] = 0.560021497822319;
   fWeightMatrix0to1[6][6] = 0.804945165723198;
   fWeightMatrix0to1[7][6] = 1.38290967695041;
   fWeightMatrix0to1[8][6] = -8.60775516825432;
   fWeightMatrix0to1[9][6] = 2.05930835027419;
   fWeightMatrix0to1[10][6] = -5.16477569772452;
   fWeightMatrix0to1[11][6] = -3.53878815327319;
   fWeightMatrix0to1[12][6] = -2.8269637853896;
   fWeightMatrix0to1[13][6] = 2.58241011829032;
   fWeightMatrix0to1[14][6] = 1.18973918097252;
   fWeightMatrix0to1[15][6] = 1.15740935720357;
   fWeightMatrix0to1[0][7] = 0.385932429732322;
   fWeightMatrix0to1[1][7] = 0.0612841538929539;
   fWeightMatrix0to1[2][7] = -1.10962638431868;
   fWeightMatrix0to1[3][7] = 1.17853665147407;
   fWeightMatrix0to1[4][7] = -0.218498762161885;
   fWeightMatrix0to1[5][7] = -0.355628692482147;
   fWeightMatrix0to1[6][7] = 0.144554669690579;
   fWeightMatrix0to1[7][7] = -0.297250960737563;
   fWeightMatrix0to1[8][7] = 0.241223128005423;
   fWeightMatrix0to1[9][7] = -1.15506224988268;
   fWeightMatrix0to1[10][7] = -0.304350273319834;
   fWeightMatrix0to1[11][7] = 0.396800920416626;
   fWeightMatrix0to1[12][7] = -0.513265296024936;
   fWeightMatrix0to1[13][7] = -0.0076975766317746;
   fWeightMatrix0to1[14][7] = 1.13600874162854;
   fWeightMatrix0to1[15][7] = -0.31370481952303;
   fWeightMatrix0to1[0][8] = 0.458443996317282;
   fWeightMatrix0to1[1][8] = 2.54290461740471;
   fWeightMatrix0to1[2][8] = 0.581654696359296;
   fWeightMatrix0to1[3][8] = 0.0956152552315091;
   fWeightMatrix0to1[4][8] = -0.150790474222591;
   fWeightMatrix0to1[5][8] = -4.89314714111423;
   fWeightMatrix0to1[6][8] = -0.557074344029645;
   fWeightMatrix0to1[7][8] = 1.45745795984405;
   fWeightMatrix0to1[8][8] = -3.90956269985166;
   fWeightMatrix0to1[9][8] = 0.838078073334763;
   fWeightMatrix0to1[10][8] = 0.562330915687419;
   fWeightMatrix0to1[11][8] = -2.13963648910626;
   fWeightMatrix0to1[12][8] = 0.507119848179024;
   fWeightMatrix0to1[13][8] = -0.71379658027336;
   fWeightMatrix0to1[14][8] = 0.109241888216747;
   fWeightMatrix0to1[15][8] = -0.108087697860001;
   fWeightMatrix0to1[0][9] = 1.97581153169439;
   fWeightMatrix0to1[1][9] = 0.028056008454378;
   fWeightMatrix0to1[2][9] = 0.709999689332406;
   fWeightMatrix0to1[3][9] = -2.52320057237195;
   fWeightMatrix0to1[4][9] = 0.336328764156242;
   fWeightMatrix0to1[5][9] = 0.695421043857276;
   fWeightMatrix0to1[6][9] = -0.369098363756398;
   fWeightMatrix0to1[7][9] = 0.914807733633563;
   fWeightMatrix0to1[8][9] = 1.24736649552052;
   fWeightMatrix0to1[9][9] = 0.621689091187065;
   fWeightMatrix0to1[10][9] = -1.37372901164192;
   fWeightMatrix0to1[11][9] = -1.72858469854534;
   fWeightMatrix0to1[12][9] = -0.801788965096738;
   fWeightMatrix0to1[13][9] = 0.0673521273820114;
   fWeightMatrix0to1[14][9] = -2.10408640217451;
   fWeightMatrix0to1[15][9] = 0.702849790391043;
   fWeightMatrix0to1[0][10] = 3.24378470660049;
   fWeightMatrix0to1[1][10] = 0.607578545563901;
   fWeightMatrix0to1[2][10] = 0.269665800049248;
   fWeightMatrix0to1[3][10] = -1.97807414719097;
   fWeightMatrix0to1[4][10] = -4.39958516939328;
   fWeightMatrix0to1[5][10] = -0.892205494093154;
   fWeightMatrix0to1[6][10] = -0.178096284695463;
   fWeightMatrix0to1[7][10] = 1.36819069899576;
   fWeightMatrix0to1[8][10] = 0.152494772725757;
   fWeightMatrix0to1[9][10] = -0.554960686495947;
   fWeightMatrix0to1[10][10] = 2.41727887679898;
   fWeightMatrix0to1[11][10] = -4.02982257522947;
   fWeightMatrix0to1[12][10] = -0.191959655765603;
   fWeightMatrix0to1[13][10] = -0.522560800762319;
   fWeightMatrix0to1[14][10] = 2.52412097328555;
   fWeightMatrix0to1[15][10] = -5.22252065797095;
   fWeightMatrix0to1[0][11] = -2.77224705673078;
   fWeightMatrix0to1[1][11] = 0.0879448991830076;
   fWeightMatrix0to1[2][11] = 6.46192029350164;
   fWeightMatrix0to1[3][11] = -2.11554354835034;
   fWeightMatrix0to1[4][11] = -10.5688496866349;
   fWeightMatrix0to1[5][11] = 2.70045678346094;
   fWeightMatrix0to1[6][11] = -12.5249502455725;
   fWeightMatrix0to1[7][11] = -2.03867122585948;
   fWeightMatrix0to1[8][11] = -5.74948841685357;
   fWeightMatrix0to1[9][11] = -9.60973316652793;
   fWeightMatrix0to1[10][11] = 0.213225886644294;
   fWeightMatrix0to1[11][11] = -2.66440225702602;
   fWeightMatrix0to1[12][11] = -18.6182436978652;
   fWeightMatrix0to1[13][11] = -6.3577763385419;
   fWeightMatrix0to1[14][11] = -3.12287835005928;
   fWeightMatrix0to1[15][11] = 1.17291378462543;
   // weight matrix from layer 1 to 2
   fWeightMatrix1to2[0][0] = 1.18404569590354;
   fWeightMatrix1to2[0][1] = 0.87977560752305;
   fWeightMatrix1to2[0][2] = -0.987397727872187;
   fWeightMatrix1to2[0][3] = 0.988910060514882;
   fWeightMatrix1to2[0][4] = 0.710242222725432;
   fWeightMatrix1to2[0][5] = 0.832784015647406;
   fWeightMatrix1to2[0][6] = -2.50121493470165;
   fWeightMatrix1to2[0][7] = -2.26720822651289;
   fWeightMatrix1to2[0][8] = -0.575967501992675;
   fWeightMatrix1to2[0][9] = 0.786827940518876;
   fWeightMatrix1to2[0][10] = -1.40664001545837;
   fWeightMatrix1to2[0][11] = -0.67475577847354;
   fWeightMatrix1to2[0][12] = 0.838428613414299;
   fWeightMatrix1to2[0][13] = 0.801710776015051;
   fWeightMatrix1to2[0][14] = -0.863975134849707;
   fWeightMatrix1to2[0][15] = -0.850886823741654;
   fWeightMatrix1to2[0][16] = -0.320120759452642;
}

inline double ReadMLP_ReLu::GetMvaValue__( const std::vector<double>& inputValues ) const
{
   if (inputValues.size() != (unsigned int)fLayerSize[0]-1) {
      std::cout << "Input vector needs to be of size " << fLayerSize[0]-1 << std::endl;
      return 0;
   }

   for (int l=0; l<fLayers; l++)
      for (int i=0; i<fLayerSize[l]; i++) fWeights[l][i]=0;

   for (int l=0; l<fLayers-1; l++)
      fWeights[l][fLayerSize[l]-1]=1;

   for (int i=0; i<fLayerSize[0]-1; i++)
      fWeights[0][i]=inputValues[i];

   // layer 0 to 1
   for (int o=0; o<fLayerSize[1]-1; o++) {
      for (int i=0; i<fLayerSize[0]; i++) {
         double inputVal = fWeightMatrix0to1[o][i] * fWeights[0][i];
         fWeights[1][o] += inputVal;
      }
      fWeights[1][o] = ActivationFnc(fWeights[1][o]);
   }
   // layer 1 to 2
   for (int o=0; o<fLayerSize[2]; o++) {
      for (int i=0; i<fLayerSize[1]; i++) {
         double inputVal = fWeightMatrix1to2[o][i] * fWeights[1][i];
         fWeights[2][o] += inputVal;
      }
      fWeights[2][o] = OutputActivationFnc(fWeights[2][o]);
   }

   return fWeights[2][0];
}

double ReadMLP_ReLu::ActivationFnc(double x) const {
   // rectified linear unit
   return x>0 ? x : 0; 
}
double ReadMLP_ReLu::OutputActivationFnc(double x) const {
   // sigmoid
   return 1.0/(1.0+exp(-x));
}
   
// Clean up
inline void ReadMLP_ReLu::Clear() 
{
   // clean up the arrays
   for (int lIdx = 0; lIdx < 3; lIdx++) {
      delete[] fWeights[lIdx];
   }
}
   inline double ReadMLP_ReLu::GetMvaValue( const std::vector<double>& inputValues ) const
   {
      // classifier response value
      double retval = 0;

      // classifier response, sanity check first
      if (!IsStatusClean()) {
         std::cout << "Problem in class \"" << fClassName << "\": cannot return classifier response"
                   << " because status is dirty" << std::endl;
         retval = 0;
      }
      else {
         if (IsNormalised()) {
            // normalise variables
            std::vector<double> iV;
            iV.reserve(inputValues.size());
            int ivar = 0;
            for (std::vector<double>::const_iterator varIt = inputValues.begin();
                 varIt != inputValues.end(); varIt++, ivar++) {
               iV.push_back(NormVariable( *varIt, fVmin[ivar], fVmax[ivar] ));
            }
            Transform( iV, -1 );
            retval = GetMvaValue__( iV );
         }
         else {
            std::vector<double> iV;
            int ivar = 0;
            for (std::vector<double>::const_iterator varIt = inputValues.begin();
                 varIt != inputValues.end(); varIt++, ivar++) {
               iV.push_back(*varIt);
            }
            Transform( iV, -1 );
            retval = GetMvaValue__( iV );
         }
      }

      return retval;
   }

//_______________________________________________________________________
void ReadMLP_ReLu::InitTransform_1()
{
   // Normalization transformation, initialisation
   fMin_1[0][0] = 0.000145583398989;
   fMax_1[0][0] = 19.9942340851;
   fMin_1[1][0] = 2.53958387475e-06;
   fMax_1[1][0] = 19.9998607635;
   fMin_1[2][0] = 2.53958387475e-06;
   fMax_1[2][0] = 19.9998607635;
   fMin_1[0][1] = 3.25623623212e-05;
   fMax_1[0][1] = 129.060302734;
   fMin_1[1][1] = 3.06161314256e-06;
   fMax_1[1][1] = 144.506576538;
   fMin_1[2][1] = 3.06161314256e-06;
   fMax_1[2][1] = 144.506576538;
   fMin_1[0][2] = 7.4331946962e-05;
   fMax_1[0][2] = 189.202789307;
   fMin_1[1][2] = 7.40608538763e-06;
   fMax_1[1][2] = 213.78477478;
   fMin_1[2][2] = 7.40608538763e-06;
   fMax_1[2][2] = 213.78477478;
   fMin_1[0][3] = 2;
   fMax_1[0][3] = 6;
   fMin_1[1][3] = 2;
   fMax_1[1][3] = 7;
   fMin_1[2][3] = 2;
   fMax_1[2][3] = 7;
   fMin_1[0][4] = 1578.93847656;
   fMax_1[0][4] = 59624.15625;
   fMin_1[1][4] = 1512.32067871;
   fMax_1[1][4] = 59981.125;
   fMin_1[2][4] = 1512.32067871;
   fMax_1[2][4] = 59981.125;
   fMin_1[0][5] = 3.15291548425e-09;
   fMax_1[0][5] = 0.355215340853;
   fMin_1[1][5] = 6.37720631858e-08;
   fMax_1[1][5] = 0.379455000162;
   fMin_1[2][5] = 3.15291548425e-09;
   fMax_1[2][5] = 0.379455000162;
   fMin_1[0][6] = 3.16174214277e-06;
   fMax_1[0][6] = 0.272405803204;
   fMin_1[1][6] = 7.10363892154e-08;
   fMax_1[1][6] = 0.287686437368;
   fMin_1[2][6] = 7.10363892154e-08;
   fMax_1[2][6] = 0.287686437368;
   fMin_1[0][7] = 0.00361165031791;
   fMax_1[0][7] = 5.78106117249;
   fMin_1[1][7] = 0.00242633954622;
   fMax_1[1][7] = 6.02552223206;
   fMin_1[2][7] = 0.00242633954622;
   fMax_1[2][7] = 6.02552223206;
   fMin_1[0][8] = 8.88151931763;
   fMax_1[0][8] = 5987.31591797;
   fMin_1[1][8] = 8.55697345734;
   fMax_1[1][8] = 5817.39257812;
   fMin_1[2][8] = 8.55697345734;
   fMax_1[2][8] = 5987.31591797;
   fMin_1[0][9] = 8;
   fMax_1[0][9] = 32;
   fMin_1[1][9] = 8;
   fMax_1[1][9] = 32;
   fMin_1[2][9] = 8;
   fMax_1[2][9] = 32;
   fMin_1[0][10] = 0;
   fMax_1[0][10] = 17;
   fMin_1[1][10] = 0;
   fMax_1[1][10] = 18;
   fMin_1[2][10] = 0;
   fMax_1[2][10] = 18;
}

//_______________________________________________________________________
inline void ReadMLP_ReLu::Transform_1( std::vector<double>& iv, int cls) const
{
   // Normalization transformation
   if (cls < 0 || cls > 2) {
   if (2 > 1 ) cls = 2;
      else cls = 2;
   }
   const int nVar = 11;

   // get indices of used variables

   // define the indices of the variables which are transformed by this transformation
   static std::vector<int> indicesGet;
   static std::vector<int> indicesPut;

   if ( indicesGet.empty() ) { 
      indicesGet.reserve(fNvars);
      indicesGet.push_back( 0);
      indicesGet.push_back( 1);
      indicesGet.push_back( 2);
      indicesGet.push_back( 3);
      indicesGet.push_back( 4);
      indicesGet.push_back( 5);
      indicesGet.push_back( 6);
      indicesGet.push_back( 7);
      indicesGet.push_back( 8);
      indicesGet.push_back( 9);
      indicesGet.push_back( 10);
   } 
   if ( indicesPut.empty() ) { 
      indicesPut.reserve(fNvars);
      indicesPut.push_back( 0);
      indicesPut.push_back( 1);
      indicesPut.push_back( 2);
      indicesPut.push_back( 3);
      indicesPut.push_back( 4);
      indicesPut.push_back( 5);
      indicesPut.push_back( 6);
      indicesPut.push_back( 7);
      indicesPut.push_back( 8);
      indicesPut.push_back( 9);
      indicesPut.push_back( 10);
   } 

   static std::vector<double> dv;
   dv.resize(nVar);
   for (int ivar=0; ivar<nVar; ivar++) dv[ivar] = iv[indicesGet.at(ivar)];
   for (int ivar=0;ivar<11;ivar++) {
      double offset = fMin_1[cls][ivar];
      double scale  = 1.0/(fMax_1[cls][ivar]-fMin_1[cls][ivar]);
      iv[indicesPut.at(ivar)] = (dv[ivar]-offset)*scale * 2 - 1;
   }
}

//_______________________________________________________________________
void ReadMLP_ReLu::InitTransform()
{
   InitTransform_1();
}

//_______________________________________________________________________
void ReadMLP_ReLu::Transform( std::vector<double>& iv, int sigOrBgd ) const
{
   Transform_1( iv, sigOrBgd );
}
