// This program takes the outfile from the flight path out toward the
// neutrino gravitational focus and creates a stacked histogram 



void TwoDHitMapAuto() {  // file for opening
  
  //First Hist to Open


for(int i =1; i<=10; i++)
    {

      string indexstr = std::to_string(i);
      string nameFile1;
      string nameFile2;
      string nameFile3;
      string nameFile4;
      string nameFile5;
      string nameFile;


      
  if(i<10)
    {
      nameFile1 = "tau-+1000+-100+-2" + indexstr + "0";
      nameFile2 = "tau-+1000+0+-2" + indexstr + "0";
      nameFile3 = "tau-+1000+100+-2" + indexstr + "0";
      nameFile4 = "tau-+1000+200+-2" + indexstr + "0";
      nameFile5 = "tau-+1000+-200+-2" + indexstr + "0";
      nameFile = "Tau_1000GeV_"+indexstr+"0kmDepth.png";
    }
  else
    {
      nameFile1 = "tau-+1000+-100+-300";
      nameFile2 = "tau-+1000+0+-300";
      nameFile3 = "tau-+1000+100+-300";
      nameFile4 = "tau-+1000+200+-300";
      nameFile5 = "tau-+1000+-200+-300";
      nameFile = "Tau_1000GeV_100kmDepth.png";
    }
  
 
  
  const char *nameHistConverted1 = nameFile1.c_str();
  const char *nameHistConverted2 = nameFile2.c_str();
  const char *nameHistConverted3 = nameFile3.c_str();
  const char *nameHistConverted4 = nameFile4.c_str();
  const char *nameHistConverted5 = nameFile5.c_str();

  
  string nameFRoot1 = nameFile1 + ".root";
 
  string nameFRoot2 = nameFile2 + ".root";

  string nameFRoot3 = nameFile3 + ".root";
  
  string nameFRoot4 = nameFile4 + ".root";

  string nameFRoot5 = nameFile5 + ".root";

  
  const char *nameFRootConverted1 = nameFRoot1.c_str();
  const char *nameFRootConverted2 = nameFRoot2.c_str();
  const char *nameFRootConverted3 = nameFRoot3.c_str();
  const char *nameFRootConverted4 = nameFRoot4.c_str();
  const char *nameFRootConverted5 = nameFRoot5.c_str();

  
  const char *printName = nameFile.c_str();
  
  TFile* myFile1 = new TFile(nameFRootConverted1);
  TFile* myFile2 = new TFile(nameFRootConverted2);
  TFile* myFile3 = new TFile(nameFRootConverted3);
  TFile* myFile4 = new TFile(nameFRootConverted4);
  TFile* myFile5 = new TFile(nameFRootConverted5);


  
  

     /*
  TH2D* Hist1 = new TH2D(nameHistConverted1,"Cherenkov Hits", 100, -50000, 50000,100, -50000, 50000);
  TH2D* Hist2 = new TH2D(nameHistConverted2,"Cherenkov Hits", 100, -50000, 50000,100, -50000, 50000);
  TH2D* Hist3 = new TH2D(nameHistConverted3,"Cherenkov Hits", 100, -50000, 50000,100, -50000, 50000);
  TH2D* Hist4 = new TH2D(nameHistConverted4,"Cherenkov Hits", 100, -50000, 50000,100, -50000, 50000);
  */
  
   TH2D* Hist1 = new TH2D(nameHistConverted1,"Cherenkov Hit Distribution 100km Above Surface;X Position (km);Y Position (km)", 80, -40, 40, 80, -40, 40);
   TH2D* Hist2 = new TH2D(nameHistConverted2,"Cherenkov Hit Distribution 200km Above Surface;X Position (km);Y Position (km)", 80, -40, 40, 80, -40, 40);
   TH2D* Hist3 = new TH2D(nameHistConverted3,"Cherenkov Hit Distribution 300km Above Surface;X Position (km);Y Position (km)", 80, -40, 40, 80, -40, 40);
   TH2D* Hist4 = new TH2D(nameHistConverted4,"Cherenkov Hit Distribution 400km Above Surface;X Position (km);Y Position (km)", 80, -40, 40, 80, -40, 40);
   TH2D* Hist5 = new TH2D(nameHistConverted5,"Cherenkov Hit Distribution at the Surface ;X Position (km);Y Position (km)", 80, -40, 40, 80, -40, 40);
  
  
  struct eventStruct{
    Double_t PositionX1;
    Double_t PositionY1;
    
    Double_t PositionX2;
    Double_t PositionY2;
    
    Double_t PositionX3;
    Double_t PositionY3;
    
    Double_t PositionX4;
    Double_t PositionY4;

    Double_t PositionX5;
    Double_t PositionY5;
    
  };
  eventStruct myEvent;

  
  TTree*myTree1;
  TTree*myTree2;
  TTree*myTree3;
  TTree*myTree4;
  TTree*myTree5;

  
  //TTree*myTreeY;
 


  
  myFile1->GetObject("Spectrum of Position hits;1",myTree1);
    
  myTree1->SetBranchAddress("PositionX", &(myEvent.PositionX1) );
  myTree1->SetBranchAddress("PositionY", &(myEvent.PositionY1) );

  
  myFile2->GetObject("Spectrum of Position hits;1",myTree2);
    
  myTree2->SetBranchAddress("PositionX", &(myEvent.PositionX2) );
  myTree2->SetBranchAddress("PositionY", &(myEvent.PositionY2) );

  
  myFile3->GetObject("Spectrum of Position hits;1",myTree3);
    
  myTree3->SetBranchAddress("PositionX", &(myEvent.PositionX3) );
  myTree3->SetBranchAddress("PositionY", &(myEvent.PositionY3) );

  myFile4->GetObject("Spectrum of Position hits;1",myTree4);
    
  myTree4->SetBranchAddress("PositionX", &(myEvent.PositionX4) );
  myTree4->SetBranchAddress("PositionY", &(myEvent.PositionY4) );

  myFile5->GetObject("Spectrum of Position hits;1",myTree5);
    
  myTree5->SetBranchAddress("PositionX", &(myEvent.PositionX5) );
  myTree5->SetBranchAddress("PositionY", &(myEvent.PositionY5) );
  

  
  gROOT->ForceStyle();
  
  
  
 

  
  unsigned int mysize1 = myTree1->GetEntries();
  unsigned int mysize2 = myTree2->GetEntries();
  unsigned int mysize3 = myTree3->GetEntries();
  unsigned int mysize4 = myTree4->GetEntries();
  unsigned int mysize5 = myTree5->GetEntries();


  
  //std::cout << mysize << std::endl;
  
  for (unsigned int i = 0; i < mysize1; ++i) {
    myTree1->GetEntry(i);
    //std::cout << myEvent.PositionY << std::endl;
    Double_t x1 = myEvent.PositionX1;
    Double_t y1 = myEvent.PositionY1;
    Hist1->Fill(x1/1000,y1/1000);
    
  }
  
  for (unsigned int i = 0; i < mysize2; ++i) {
    myTree2->GetEntry(i);
    //std::cout << myEvent.PositionY << std::endl;
    Double_t x2 = myEvent.PositionX2;
    Double_t y2 = myEvent.PositionY2;
    Hist2->Fill(x2/1000,y2/1000);
    
  }

  for (unsigned int i = 0; i < mysize3; ++i) {
    myTree3->GetEntry(i);
    //std::cout << myEvent.PositionY << std::endl;
    Double_t x3 = myEvent.PositionX3;
    Double_t y3 = myEvent.PositionY3;
    Hist3->Fill(x3/1000,y3/1000);
    
  }

  for (unsigned int i = 0; i < mysize4; ++i) {
    myTree4->GetEntry(i);
    //std::cout << myEvent.PositionY << std::endl;
    Double_t x4 = myEvent.PositionX4;
    Double_t y4 = myEvent.PositionY4;
    Hist4->Fill(x4/1000,y4/1000);
    
  }

 for (unsigned int i = 0; i < mysize5; ++i) {
    myTree5->GetEntry(i);
    //std::cout << myEvent.PositionY << std::endl;
    Double_t x5 = myEvent.PositionX5;
    Double_t y5 = myEvent.PositionY5;
    Hist5->Fill(x5/1000,y5/1000);
    
  }



  auto canvas_1 = new TCanvas("canvas1","canvas1", 2500, 2500);
  
  //TCanvas* canvas_1 = new TCanvas("canvas1","canvas1");

  gStyle->SetPalette(kRainBow);
  
  canvas_1->Divide(3,2);

  /*
  canvas_1->cd(1);
  Hist1 ->SetContour(100000);
  Hist1->Draw("colz");
  
  canvas_1->cd(2);
  Hist2 ->SetContour(100000);
  Hist2->Draw("colz");

  canvas_1->cd(3);
  Hist3 ->SetContour(100000);
  Hist3->Draw("colz");
  

  canvas_1->cd(4);
  Hist4 ->SetContour(100000);
  Hist4->Draw("colz");
  */

  canvas_1->cd(1);
  Hist5 ->SetContour(100000);
  Hist5->Draw("colz");
  /*
  gPad->Update();
  TPaletteAxis* palette1 = (TPaletteAxis*)Hist5->GetListOfFunctions()->FindObject("palette");
  palette1->SetX1NDC(0.9);
  palette1->SetX2NDC(0.92);
  palette1->SetY2NDC(0.68);
  */

    
  canvas_1->cd(3);
  Hist1 ->SetContour(100000);
  Hist1->Draw("colz");
  
  /*
  gPad->Update();
  TPaletteAxis* palette2 = (TPaletteAxis*)Hist1->GetListOfFunctions()->FindObject("palette");
  palette2->SetX1NDC(0.9);
  palette2->SetX2NDC(0.92);
  palette2->SetY2NDC(0.68);
  */
  
  canvas_1->cd(4);
  Hist2 ->SetContour(100000);
  Hist2->Draw("colz");
  /*
 gPad->Update();
  TPaletteAxis* palette3 = (TPaletteAxis*)Hist2->GetListOfFunctions()->FindObject("palette");
  palette3->SetX1NDC(0.9);
  palette3->SetX2NDC(0.92);
  palette3->SetY2NDC(0.68);
  */

  
  canvas_1->cd(5);
  Hist3 ->SetContour(100000);
  Hist3->Draw("colz");

  /*
  gPad->Update();
  TPaletteAxis* palette4 = (TPaletteAxis*)Hist3->GetListOfFunctions()->FindObject("palette");
  palette4->SetX1NDC(0.9);
  palette4->SetX2NDC(0.92);
  palette4->SetY2NDC(0.68);
  */

  canvas_1->cd(6);
  Hist4 ->SetContour(100000);
  Hist4->Draw("colz");

  /*
  gPad->Update();
  TPaletteAxis* palette5 = (TPaletteAxis*)Hist4->GetListOfFunctions()->FindObject("palette");
  palette5->SetX1NDC(0.9);
  palette5->SetX2NDC(0.92);
  palette5->SetY2NDC(0.68);
  */

  


  //canvas_1->SetCanvasSize(2500,2500);
  //canvas_1->SetWindowSize(400,400);
  
  
  canvas_1->Draw();

  
  canvas_1->Print(printName);
  

  
  
  
 
 
  
    }

}











