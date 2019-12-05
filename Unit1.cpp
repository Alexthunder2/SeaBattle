//---------------------------------------------------------------------------
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Graphics::TBitmap  *k4h=new Graphics::TBitmap(), *k3h=new Graphics::TBitmap(), *k2h=new Graphics::TBitmap(), *k1=new Graphics::TBitmap(), *ris=new Graphics::TBitmap(), *k4v=new Graphics::TBitmap(), *k3v=new Graphics::TBitmap(), *k2v=new Graphics::TBitmap, *krest=new Graphics::TBitmap();
TRect Pr4h, Pr3h, Pr2h, Pr1, Pr4v, Pr3v, Pr2v, P01, P02v, P02h, P03v, P03h, P04v, P04h;
int done=0, done2=0, done3=0,done4=0, end=0, ywin=0, cwin=0, a[20][20], m[20][20], c[20][20],level=0, tyk, si=0, situ=0, ad1[4], ad2[2], ad3[2], ka=0,  start=0, ch1=0,ch2=0,ch3=0, per=0, got=0, hod=0,bit=0, ra=0, gotovo=0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
for (int i=0; i < 4; i++) {
	ad1[i]=0;
	if (i<2)
	{
	ad2[i]=0;
	ad3[i]=0;
	}
}
  for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
		m[i][j]=1;
Image1->Canvas->Brush->Color = clGray;
	Image1->Canvas->Rectangle(0,0,400,400);
	Image3->Canvas->Brush->Color = clSkyBlue;
	Image3->Canvas->Rectangle(0,0,160,160);
		Image4->Canvas->Brush->Color = clSkyBlue;
	Image4->Canvas->Rectangle(0,0,120,120);
		Image5->Canvas->Brush->Color = clSkyBlue;
	Image5->Canvas->Rectangle(0,0,80,80);
  for (int i=0; i < 9; i++) {
  Image1->Canvas->MoveTo(0,(i+1)*40);
	Image1->Canvas->LineTo(400,(i+1)*40);
	Image1->Canvas->MoveTo((i+1)*40,0);
	Image1->Canvas->LineTo((i+1)*40,400);
}
Image2->Canvas->Brush->Color = clGray;
	Image2->Canvas->Rectangle(0,0,400,400);
  for (int i=0; i < 9; i++) {
  Image2->Canvas->MoveTo(0,(i+1)*40);
	Image2->Canvas->LineTo(400,(i+1)*40);
	Image2->Canvas->MoveTo((i+1)*40,0);
	Image2->Canvas->LineTo((i+1)*40,400);
}
 ris->Width=160;
 ris->Height=320;
 ris -> LoadFromFile("karabli.bmp");
 krest->Width=40;
 krest->Height=40;
 krest -> LoadFromFile("krest.bmp");
 krest->Transparent=True;
 Pr4h=Bounds(0,0,160,40);
 Pr3h=Bounds(0,40,120,40);
 Pr2h=Bounds(0,80,80,40);
 Pr4v=Bounds(0,160,40,160);
 Pr3v=Bounds(40,160,40,120);
 Pr2v=Bounds(80,160,40,80);
 Pr1=Bounds(0,120,40,40);
 P04h=Bounds(0,0,160,40);
 P03h=Bounds(0,0,120,40);
 P02h=Bounds(0,0,80,40);
 P04v=Bounds(0,0,40,160);
 P03v=Bounds(0,0,40,120);
 P02v=Bounds(0,0,40,80);
 P01=Bounds(0,0,40,40);
 k4h->Width=160;
 k4h->Height=40;
 k3h->Width=120;
 k3h->Height=40;
 k2h->Width=80;
 k2h->Height=40;
 k4v->Width=40;
 k4v->Height=160;
 k3v->Width=40;
 k3v->Height=120;
 k2v->Width=40;
 k2v->Height=80;
 k1->Width=40;
 k1->Height=40;
 k4h->Canvas->CopyRect(P04h,ris->Canvas,Pr4h);
 k4v->Canvas->CopyRect(P04v,ris->Canvas,Pr4v);
 k3h->Canvas->CopyRect(P03h,ris->Canvas,Pr3h);
 k3v->Canvas->CopyRect(P03v,ris->Canvas,Pr3v);
 k2h->Canvas->CopyRect(P02h,ris->Canvas,Pr2h);
 k2v->Canvas->CopyRect(P02v,ris->Canvas,Pr2v);
 k1->Canvas->CopyRect(P01,ris->Canvas,Pr1);
 Image3->Canvas->Draw(0,0,k4h);
 Image4->Canvas->Draw(0,0,k3h);
 Image5->Canvas->Draw(0,0,k2h);
 Image6->Canvas->Draw(0,0,k1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
		 int X1=X;
		 int Y1=Y;
		 Label4->Visible=False;
		 gotovo=0;
		 if ((X1<400)&&(Y1<400)&&(hod==0)&&(end==0))
		  {
			if (a[Y1/40][X1/40]==1) {
			 Image1->Canvas->Brush->Color = clBlue;
			 Image1->Canvas->Rectangle((X1/40)*40,(Y1/40)*40,(X1/40+1)*40,(Y1/40+1)*40);
			 Timer1->Enabled=True;
			 hod=1;
			 a[Y1/40][X1/40]=-2;
			}
			if (a[Y1/40][X1/40]==0) {
			int pro=1;
			if ((Y1/40>0)&&(a[Y1/40-1][X1/40]==0))
				pro=0;
			if ((Y1/40>1)&&(a[Y1/40-1][X1/40]==-1)&&(a[Y1/40-2][X1/40]==0))
				pro=0;
			if ((Y1/40>2)&&(a[Y1/40-1][X1/40]==-1)&&(a[Y1/40-2][X1/40]==-1)&&(a[Y1/40-3][X1/40]==0))
				pro=0;

			 if ((Y1/40<9)&&(a[Y1/40+1][X1/40]==0))
				pro=0;
			if ((Y1/40<8)&&(a[Y1/40+1][X1/40]==-1)&&(a[Y1/40+2][X1/40]==0))
				pro=0;
			if ((Y1/40<7)&&(a[Y1/40+1][X1/40]==-1)&&(a[Y1/40+2][X1/40]==-1)&&(a[Y1/40+3][X1/40]==0))
				pro=0;

			if ((X1/40>0)&&(a[Y1/40][X1/40-1]==0))
				pro=0;
			if ((X1/40>1)&&(a[Y1/40][X1/40-1]==-1)&&(a[Y1/40][X1/40-2]==0))
				pro=0;
			if ((X1/40>2)&&(a[Y1/40][X1/40-1]==-1)&&(a[Y1/40][X1/40-2]==-1)&&(a[Y1/40][X1/40-3]==0))
				pro=0;

			if ((X1/40<9)&&(a[Y1/40][X1/40+1]==0))
				pro=0;
			if ((X1/40<8)&&(a[Y1/40][X1/40+1]==-1)&&(a[Y1/40][X1/40+2]==0))
				pro=0;
			if ((X1/40<7)&&(a[Y1/40][X1/40+1]==-1)&&(a[Y1/40][X1/40+2]==-1)&&(a[Y1/40][X1/40+3]==0))
				pro=0;

				if (pro==0) {

			 Image1->Canvas->Brush->Color = clYellow;
			 Image1->Canvas->Rectangle((X1/40)*40,(Y1/40)*40,(X1/40+1)*40,(Y1/40+1)*40);
			 a[Y1/40][X1/40]=-1;
			 ywin++;
				}
					if (pro==1) {

			 Image1->Canvas->Brush->Color = clRed;
			 Image1->Canvas->Rectangle((X1/40)*40,(Y1/40)*40,(X1/40+1)*40,(Y1/40+1)*40);
			 ywin++;
			 if ((X1/40>0)&&(Y1/40>0)) {
			  Image1->Canvas->Brush->Color = clBlue;
			 Image1->Canvas->Rectangle((X1/40-1)*40,(Y1/40-1)*40,(X1/40)*40,(Y1/40)*40);
			 }
			  if ((X1/40>0)&&(Y1/40<9)) {
			  Image1->Canvas->Brush->Color = clBlue;
			 Image1->Canvas->Rectangle((X1/40-1)*40,(Y1/40+1)*40,(X1/40)*40,(Y1/40+2)*40);
			 }
			 if ((X1/40<9)&&(Y1/40<9)) {
			  Image1->Canvas->Brush->Color = clBlue;
			 Image1->Canvas->Rectangle((X1/40+1)*40,(Y1/40+1)*40,(X1/40+2)*40,(Y1/40+2)*40);
			 }
			 if ((X1/40<9)&&(Y1/40>0)) {
			  Image1->Canvas->Brush->Color = clBlue;
			 Image1->Canvas->Rectangle((X1/40+1)*40,(Y1/40-1)*40,(X1/40+2)*40,(Y1/40)*40);
			 }
			 a[Y1/40][X1/40]=-1;
				if ((Y1/40>0)&&(a[Y1/40-1][X1/40]!=-1))
				  {
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40)*40,(Y1/40-1)*40,(X1/40+1)*40,(Y1/40)*40);
				  }
				  if ((Y1/40==1)&&(a[Y1/40-1][X1/40]==-1))
				  {
					Image1->Canvas->Brush->Color = clRed;
					Image1->Canvas->Rectangle((X1/40)*40,(Y1/40-1)*40,(X1/40+1)*40,(Y1/40)*40);
					Image1->Canvas->Brush->Color = clBlue;
					if (X1/40>0)
					Image1->Canvas->Rectangle((X1/40-1)*40,(Y1/40)*40,(X1/40)*40,(Y1/40+1)*40);
					if (X1/40<9)
					Image1->Canvas->Rectangle((X1/40+1)*40,(Y1/40)*40,(X1/40+2)*40,(Y1/40+1)*40);
				  }
				 if ((Y1/40>1)&&(a[Y1/40-1][X1/40]==-1)&&(a[Y1/40-2][X1/40]!=-1))
				  {
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40)*40,(Y1/40-2)*40,(X1/40+1)*40,(Y1/40-1)*40);
					Image1->Canvas->Brush->Color = clRed;
					Image1->Canvas->Rectangle((X1/40)*40,(Y1/40-1)*40,(X1/40+1)*40,(Y1/40)*40);
					if (X1/40>0)
					{
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40-1)*40,(Y1/40)*40,(X1/40)*40,(Y1/40+1)*40);
					Image1->Canvas->Rectangle((X1/40-1)*40,(Y1/40-2)*40,(X1/40)*40,(Y1/40-1)*40);
					}
					if (X1/40<9)
					{
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40+1)*40,(Y1/40)*40,(X1/40+2)*40,(Y1/40+1)*40);
					Image1->Canvas->Rectangle((X1/40+1)*40,(Y1/40-2)*40,(X1/40+2)*40,(Y1/40-1)*40);
					}
				  }
				 if ((Y1/40==2)&&(a[Y1/40-1][X1/40]==-1)&&(a[Y1/40-2][X1/40]==-1))
				 {
				   Image1->Canvas->Brush->Color = clRed;
					Image1->Canvas->Rectangle((X1/40)*40,(Y1/40-1)*40,(X1/40+1)*40,(Y1/40)*40);
					Image1->Canvas->Brush->Color = clRed;
					Image1->Canvas->Rectangle((X1/40)*40,(Y1/40-2)*40,(X1/40+1)*40,(Y1/40-1)*40);
					if (X1/40>0)
					{
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40-1)*40,(Y1/40)*40,(X1/40)*40,(Y1/40+1)*40);
					Image1->Canvas->Rectangle((X1/40-1)*40,(Y1/40-2)*40,(X1/40)*40,(Y1/40-1)*40);
					}
					if (X1/40<9)
					{
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40+1)*40,(Y1/40)*40,(X1/40+2)*40,(Y1/40+1)*40);
					Image1->Canvas->Rectangle((X1/40+1)*40,(Y1/40-2)*40,(X1/40+2)*40,(Y1/40-1)*40);
					}
				 }
				 if ((Y1/40>2)&&(a[Y1/40-1][X1/40]==-1)&&(a[Y1/40-2][X1/40]==-1)&&(a[Y1/40-3][X1/40]!=-1))
				  {
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40)*40,(Y1/40-3)*40,(X1/40+1)*40,(Y1/40-2)*40);
					Image1->Canvas->Brush->Color = clRed;
					Image1->Canvas->Rectangle((X1/40)*40,(Y1/40-1)*40,(X1/40+1)*40,(Y1/40)*40);
					Image1->Canvas->Rectangle((X1/40)*40,(Y1/40-2)*40,(X1/40+1)*40,(Y1/40-1)*40);
					if (X1/40>0)
					{
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40-1)*40,(Y1/40)*40,(X1/40)*40,(Y1/40+1)*40);
					Image1->Canvas->Rectangle((X1/40-1)*40,(Y1/40-2)*40,(X1/40)*40,(Y1/40-1)*40);
					Image1->Canvas->Rectangle((X1/40-1)*40,(Y1/40-3)*40,(X1/40)*40,(Y1/40-2)*40);
					}
					if (X1/40<9)
					{
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40+1)*40,(Y1/40)*40,(X1/40+2)*40,(Y1/40+1)*40);
					Image1->Canvas->Rectangle((X1/40+1)*40,(Y1/40-2)*40,(X1/40+2)*40,(Y1/40-1)*40);
					Image1->Canvas->Rectangle((X1/40+1)*40,(Y1/40-3)*40,(X1/40+2)*40,(Y1/40-2)*40);
					}
				  }
				   if ((Y1/40==3)&&(a[Y1/40-1][X1/40]==-1)&&(a[Y1/40-2][X1/40]==-1)&&(a[Y1/40-3][X1/40]==-1))
				 {
				   Image1->Canvas->Brush->Color = clRed;
					Image1->Canvas->Rectangle((X1/40)*40,(Y1/40-1)*40,(X1/40+1)*40,(Y1/40)*40);
					Image1->Canvas->Brush->Color = clRed;
					Image1->Canvas->Rectangle((X1/40)*40,(Y1/40-2)*40,(X1/40+1)*40,(Y1/40-1)*40);
					Image1->Canvas->Brush->Color = clRed;
					Image1->Canvas->Rectangle((X1/40)*40,(Y1/40-3)*40,(X1/40+1)*40,(Y1/40-2)*40);
					if (X1/40>0)
					{
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40-1)*40,(Y1/40)*40,(X1/40)*40,(Y1/40+1)*40);
					Image1->Canvas->Rectangle((X1/40-1)*40,(Y1/40-2)*40,(X1/40)*40,(Y1/40-1)*40);
					Image1->Canvas->Rectangle((X1/40-1)*40,(Y1/40-3)*40,(X1/40)*40,(Y1/40-2)*40);
					}
					if (X1/40<9)
					{
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40+1)*40,(Y1/40)*40,(X1/40+2)*40,(Y1/40+1)*40);
					Image1->Canvas->Rectangle((X1/40+1)*40,(Y1/40-2)*40,(X1/40+2)*40,(Y1/40-1)*40);
					Image1->Canvas->Rectangle((X1/40+1)*40,(Y1/40-3)*40,(X1/40+2)*40,(Y1/40-2)*40);
					}
				 }
				 if ((Y1/40>3)&&(a[Y1/40-1][X1/40]==-1)&&(a[Y1/40-2][X1/40]==-1)&&(a[Y1/40-3][X1/40]==-1)&&(a[Y1/40-4][X1/40]!=-1))
				  {
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40)*40,(Y1/40-4)*40,(X1/40+1)*40,(Y1/40-3)*40);
					Image1->Canvas->Brush->Color = clRed;
					Image1->Canvas->Rectangle((X1/40)*40,(Y1/40-1)*40,(X1/40+1)*40,(Y1/40)*40);
					Image1->Canvas->Rectangle((X1/40)*40,(Y1/40-2)*40,(X1/40+1)*40,(Y1/40-1)*40);
					Image1->Canvas->Rectangle((X1/40)*40,(Y1/40-3)*40,(X1/40+1)*40,(Y1/40-2)*40);
					if (X1/40>0)
					{
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40-1)*40,(Y1/40)*40,(X1/40)*40,(Y1/40+1)*40);
					Image1->Canvas->Rectangle((X1/40-1)*40,(Y1/40-2)*40,(X1/40)*40,(Y1/40-1)*40);
					Image1->Canvas->Rectangle((X1/40-1)*40,(Y1/40-3)*40,(X1/40)*40,(Y1/40-2)*40);
					Image1->Canvas->Rectangle((X1/40-1)*40,(Y1/40-4)*40,(X1/40)*40,(Y1/40-3)*40);
					}
					if (X1/40<9)
					{
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40+1)*40,(Y1/40)*40,(X1/40+2)*40,(Y1/40+1)*40);
					Image1->Canvas->Rectangle((X1/40+1)*40,(Y1/40-2)*40,(X1/40+2)*40,(Y1/40-1)*40);
					Image1->Canvas->Rectangle((X1/40+1)*40,(Y1/40-3)*40,(X1/40+2)*40,(Y1/40-2)*40);
					Image1->Canvas->Rectangle((X1/40+1)*40,(Y1/40-4)*40,(X1/40+2)*40,(Y1/40-3)*40);
					}
				  }


				   if ((Y1/40<9)&&(a[Y1/40+1][X1/40]!=-1))
				  {
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40)*40,(Y1/40+1)*40,(X1/40+1)*40,(Y1/40+2)*40);
				  }
				  if ((Y1/40==8)&&(a[Y1/40+1][X1/40]==-1))
				  {
					Image1->Canvas->Brush->Color = clRed;
					Image1->Canvas->Rectangle((X1/40)*40,(Y1/40+1)*40,(X1/40+1)*40,(Y1/40+2)*40);
					Image1->Canvas->Brush->Color = clBlue;
					if (X1/40>0)
					Image1->Canvas->Rectangle((X1/40-1)*40,(Y1/40)*40,(X1/40)*40,(Y1/40+1)*40);
					if (X1/40<9)
					Image1->Canvas->Rectangle((X1/40+1)*40,(Y1/40)*40,(X1/40+2)*40,(Y1/40+1)*40);
				  }
				 if ((Y1/40<8)&&(a[Y1/40+1][X1/40]==-1)&&(a[Y1/40+2][X1/40]!=-1))
				  {
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40)*40,(Y1/40+2)*40,(X1/40+1)*40,(Y1/40+3)*40);
					Image1->Canvas->Brush->Color = clRed;
					Image1->Canvas->Rectangle((X1/40)*40,(Y1/40+1)*40,(X1/40+1)*40,(Y1/40+2)*40);
					if (X1/40>0)
					{
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40-1)*40,(Y1/40)*40,(X1/40)*40,(Y1/40+1)*40);
					Image1->Canvas->Rectangle((X1/40-1)*40,(Y1/40+2)*40,(X1/40)*40,(Y1/40+3)*40);
					}
					if (X1/40<9)
					{
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40+1)*40,(Y1/40)*40,(X1/40+2)*40,(Y1/40+1)*40);
					Image1->Canvas->Rectangle((X1/40+1)*40,(Y1/40+2)*40,(X1/40+2)*40,(Y1/40+3)*40);
					}
				  }
				 if ((Y1/40==7)&&(a[Y1/40+1][X1/40]==-1)&&(a[Y1/40+2][X1/40]==-1))
				 {
				   Image1->Canvas->Brush->Color = clRed;
					Image1->Canvas->Rectangle((X1/40)*40,(Y1/40+1)*40,(X1/40+1)*40,(Y1/40+2)*40);
					Image1->Canvas->Brush->Color = clRed;
					Image1->Canvas->Rectangle((X1/40)*40,(Y1/40+2)*40,(X1/40+1)*40,(Y1/40+3)*40);
					if (X1/40>0)
					{
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40-1)*40,(Y1/40)*40,(X1/40)*40,(Y1/40+1)*40);
					Image1->Canvas->Rectangle((X1/40-1)*40,(Y1/40+2)*40,(X1/40)*40,(Y1/40+3)*40);
					}
					if (X1/40<9)
					{
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40+1)*40,(Y1/40)*40,(X1/40+2)*40,(Y1/40+1)*40);
					Image1->Canvas->Rectangle((X1/40+1)*40,(Y1/40+2)*40,(X1/40+2)*40,(Y1/40+3)*40);
					}
				 }
				 if ((Y1/40<7)&&(a[Y1/40+1][X1/40]==-1)&&(a[Y1/40+2][X1/40]==-1)&&(a[Y1/40+3][X1/40]!=-1))
				  {
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40)*40,(Y1/40+3)*40,(X1/40+1)*40,(Y1/40+4)*40);
					Image1->Canvas->Brush->Color = clRed;
					Image1->Canvas->Rectangle((X1/40)*40,(Y1/40+1)*40,(X1/40+1)*40,(Y1/40+2)*40);
					Image1->Canvas->Rectangle((X1/40)*40,(Y1/40+2)*40,(X1/40+1)*40,(Y1/40+3)*40);
					if (X1/40>0)
					{
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40-1)*40,(Y1/40)*40,(X1/40)*40,(Y1/40+1)*40);
					Image1->Canvas->Rectangle((X1/40-1)*40,(Y1/40+2)*40,(X1/40)*40,(Y1/40+3)*40);
					Image1->Canvas->Rectangle((X1/40-1)*40,(Y1/40+3)*40,(X1/40)*40,(Y1/40+4)*40);
					}
					if (X1/40<9)
					{
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40+1)*40,(Y1/40)*40,(X1/40+2)*40,(Y1/40+1)*40);
					Image1->Canvas->Rectangle((X1/40+1)*40,(Y1/40+2)*40,(X1/40+2)*40,(Y1/40+3)*40);
					Image1->Canvas->Rectangle((X1/40+1)*40,(Y1/40+3)*40,(X1/40+2)*40,(Y1/40+4)*40);
					}
				  }
				   if ((Y1/40==6)&&(a[Y1/40+1][X1/40]==-1)&&(a[Y1/40+2][X1/40]==-1)&&(a[Y1/40+3][X1/40]==-1))
				 {
				   Image1->Canvas->Brush->Color = clRed;
					Image1->Canvas->Rectangle((X1/40)*40,(Y1/40+1)*40,(X1/40+1)*40,(Y1/40+2)*40);
					Image1->Canvas->Brush->Color = clRed;
					Image1->Canvas->Rectangle((X1/40)*40,(Y1/40+2)*40,(X1/40+1)*40,(Y1/40+3)*40);
					Image1->Canvas->Brush->Color = clRed;
					Image1->Canvas->Rectangle((X1/40)*40,(Y1/40+3)*40,(X1/40+1)*40,(Y1/40+4)*40);
					if (X1/40>0)
					{
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40-1)*40,(Y1/40)*40,(X1/40)*40,(Y1/40+1)*40);
					Image1->Canvas->Rectangle((X1/40-1)*40,(Y1/40+2)*40,(X1/40)*40,(Y1/40+3)*40);
					Image1->Canvas->Rectangle((X1/40-1)*40,(Y1/40+3)*40,(X1/40)*40,(Y1/40+4)*40);
					}
					if (X1/40<9)
					{
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40+1)*40,(Y1/40)*40,(X1/40+2)*40,(Y1/40+1)*40);
					Image1->Canvas->Rectangle((X1/40+1)*40,(Y1/40+2)*40,(X1/40+2)*40,(Y1/40+3)*40);
					Image1->Canvas->Rectangle((X1/40+1)*40,(Y1/40+3)*40,(X1/40+2)*40,(Y1/40+4)*40);
					}
				 }
				 if ((Y1/40<6)&&(a[Y1/40+1][X1/40]==-1)&&(a[Y1/40+2][X1/40]==-1)&&(a[Y1/40+3][X1/40]==-1)&&(a[Y1/40+4][X1/40]!=-1))
				  {
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40)*40,(Y1/40+4)*40,(X1/40+1)*40,(Y1/40+5)*40);
					Image1->Canvas->Brush->Color = clRed;
					Image1->Canvas->Rectangle((X1/40)*40,(Y1/40+1)*40,(X1/40+1)*40,(Y1/40+2)*40);
					Image1->Canvas->Rectangle((X1/40)*40,(Y1/40+2)*40,(X1/40+1)*40,(Y1/40+3)*40);
					Image1->Canvas->Rectangle((X1/40)*40,(Y1/40+3)*40,(X1/40+1)*40,(Y1/40+4)*40);
					if (X1/40>0)
					{
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40-1)*40,(Y1/40)*40,(X1/40)*40,(Y1/40+1)*40);
					Image1->Canvas->Rectangle((X1/40-1)*40,(Y1/40+2)*40,(X1/40)*40,(Y1/40+3)*40);
					Image1->Canvas->Rectangle((X1/40-1)*40,(Y1/40+3)*40,(X1/40)*40,(Y1/40+4)*40);
					Image1->Canvas->Rectangle((X1/40-1)*40,(Y1/40+4)*40,(X1/40)*40,(Y1/40+5)*40);
					}
					if (X1/40<9)
					{
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40+1)*40,(Y1/40)*40,(X1/40+2)*40,(Y1/40+1)*40);
					Image1->Canvas->Rectangle((X1/40+1)*40,(Y1/40+2)*40,(X1/40+2)*40,(Y1/40+3)*40);
					Image1->Canvas->Rectangle((X1/40+1)*40,(Y1/40+3)*40,(X1/40+2)*40,(Y1/40+4)*40);
					Image1->Canvas->Rectangle((X1/40+1)*40,(Y1/40+4)*40,(X1/40+2)*40,(Y1/40+5)*40);
					}
				  }


				  if ((X1/40>0)&&(a[Y1/40][X1/40-1]!=-1))
				  {
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40-1)*40,(Y1/40)*40,(X1/40)*40,(Y1/40+1)*40);
				  }
				  if ((X1/40==1)&&(a[Y1/40][X1/40-1]==-1))
				  {
					Image1->Canvas->Brush->Color = clRed;
					Image1->Canvas->Rectangle((X1/40-1)*40,(Y1/40)*40,(X1/40)*40,(Y1/40+1)*40);
				  }
				 if ((X1/40>1)&&(a[Y1/40][X1/40-1]==-1)&&(a[Y1/40][X1/40-2]!=-1))
				  {
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40-2)*40,(Y1/40)*40,(X1/40-1)*40,(Y1/40+1)*40);
					Image1->Canvas->Brush->Color = clRed;
					Image1->Canvas->Rectangle((X1/40-1)*40,(Y1/40)*40,(X1/40)*40,(Y1/40+1)*40);
					if (Y1/40>0)
					{
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40-2)*40,(Y1/40-1)*40,(X1/40-1)*40,(Y1/40)*40);
					}
					if (Y1/40<9)
					{
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40-2)*40,(Y1/40+1)*40,(X1/40-1)*40,(Y1/40+2)*40);
					}
				  }
				 if ((X1/40==2)&&(a[Y1/40][X1/40-1]==-1)&&(a[Y1/40][X1/40-2]==-1))
				 {
				   Image1->Canvas->Brush->Color = clRed;
					Image1->Canvas->Rectangle((X1/40-1)*40,(Y1/40)*40,(X1/40)*40,(Y1/40+1)*40);
					Image1->Canvas->Brush->Color = clRed;
					Image1->Canvas->Rectangle((X1/40-2)*40,(Y1/40)*40,(X1/40-1)*40,(Y1/40+1)*40);
					if (Y1/40>0)
					{
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40-2)*40,(Y1/40-1)*40,(X1/40-1)*40,(Y1/40)*40);
					}
					if (Y1/40<9)
					{
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40-2)*40,(Y1/40+1)*40,(X1/40-1)*40,(Y1/40+2)*40);
					}
				 }
				 if ((X1/40>2)&&(a[Y1/40][X1/40-1]==-1)&&(a[Y1/40][X1/40-2]==-1)&&(a[Y1/40][X1/40-3]!=-1))
				  {
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40-3)*40,(Y1/40)*40,(X1/40-2)*40,(Y1/40+1)*40);
					Image1->Canvas->Brush->Color = clRed;
					Image1->Canvas->Rectangle((X1/40-1)*40,(Y1/40)*40,(X1/40)*40,(Y1/40+1)*40);
					Image1->Canvas->Rectangle((X1/40-2)*40,(Y1/40)*40,(X1/40-1)*40,(Y1/40+1)*40);
					if (Y1/40>0)
					{
					Image1->Canvas->Brush->Color = clBlue;

					Image1->Canvas->Rectangle((X1/40-2)*40,(Y1/40-1)*40,(X1/40-1)*40,(Y1/40)*40);
					Image1->Canvas->Rectangle((X1/40-3)*40,(Y1/40-1)*40,(X1/40-2)*40,(Y1/40)*40);
					}
					if (Y1/40<9)
					{
					Image1->Canvas->Brush->Color = clBlue;

					Image1->Canvas->Rectangle((X1/40-2)*40,(Y1/40+1)*40,(X1/40-1)*40,(Y1/40+2)*40);
					Image1->Canvas->Rectangle((X1/40-3)*40,(Y1/40+1)*40,(X1/40-2)*40,(Y1/40+2)*40);
					}
				  }
				   if ((X1/40==3)&&(a[Y1/40][X1/40-1]==-1)&&(a[Y1/40][X1/40-2]==-1)&&(a[Y1/40][X1/40-3]==-1))
				 {
				   Image1->Canvas->Brush->Color = clRed;
					Image1->Canvas->Rectangle((X1/40-1)*40,(Y1/40)*40,(X1/40)*40,(Y1/40+1)*40);
					Image1->Canvas->Brush->Color = clRed;
					Image1->Canvas->Rectangle((X1/40-2)*40,(Y1/40)*40,(X1/40-1)*40,(Y1/40+1)*40);
					Image1->Canvas->Brush->Color = clRed;
					Image1->Canvas->Rectangle((X1/40-3)*40,(Y1/40)*40,(X1/40-2)*40,(Y1/40+1)*40);
					if (Y1/40>0)
					{
					Image1->Canvas->Brush->Color = clBlue;

					Image1->Canvas->Rectangle((X1/40-2)*40,(Y1/40-1)*40,(X1/40-1)*40,(Y1/40)*40);
					Image1->Canvas->Rectangle((X1/40-3)*40,(Y1/40-1)*40,(X1/40-2)*40,(Y1/40)*40);
					}
					if (Y1/40<9)
					{
					Image1->Canvas->Brush->Color = clBlue;

					Image1->Canvas->Rectangle((X1/40-2)*40,(Y1/40+1)*40,(X1/40-1)*40,(Y1/40+2)*40);
					Image1->Canvas->Rectangle((X1/40-3)*40,(Y1/40+1)*40,(X1/40-2)*40,(Y1/40+2)*40);
					}
				 }
				 if ((X1/40>3)&&(a[Y1/40][X1/40-1]==-1)&&(a[Y1/40][X1/40-2]==-1)&&(a[Y1/40][X1/40-3]==-1)&&(a[Y1/40][X1/40-4]!=-1))
				  {
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40-4)*40,(Y1/40)*40,(X1/40-3)*40,(Y1/40+1)*40);
					Image1->Canvas->Brush->Color = clRed;
					Image1->Canvas->Rectangle((X1/40-1)*40,(Y1/40)*40,(X1/40)*40,(Y1/40+1)*40);
					Image1->Canvas->Rectangle((X1/40-2)*40,(Y1/40)*40,(X1/40-1)*40,(Y1/40+1)*40);
					Image1->Canvas->Rectangle((X1/40-3)*40,(Y1/40)*40,(X1/40-2)*40,(Y1/40+1)*40);
					if (Y1/40>0)
					{
					Image1->Canvas->Brush->Color = clBlue;

					Image1->Canvas->Rectangle((X1/40-2)*40,(Y1/40-1)*40,(X1/40-1)*40,(Y1/40)*40);
					Image1->Canvas->Rectangle((X1/40-3)*40,(Y1/40-1)*40,(X1/40-2)*40,(Y1/40)*40);
					Image1->Canvas->Rectangle((X1/40-4)*40,(Y1/40-1)*40,(X1/40-3)*40,(Y1/40)*40);
					}
					if (Y1/40<9)
					{
					Image1->Canvas->Brush->Color = clBlue;

					Image1->Canvas->Rectangle((X1/40-2)*40,(Y1/40+1)*40,(X1/40-1)*40,(Y1/40+2)*40);
					Image1->Canvas->Rectangle((X1/40-3)*40,(Y1/40+1)*40,(X1/40-2)*40,(Y1/40+2)*40);
					Image1->Canvas->Rectangle((X1/40-4)*40,(Y1/40+1)*40,(X1/40-3)*40,(Y1/40+2)*40);
					}
				  }


					if ((X1/40<9)&&(a[Y1/40][X1/40+1]!=-1))
				  {
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40+1)*40,(Y1/40)*40,(X1/40+2)*40,(Y1/40+1)*40);
				  }
				  if ((X1/40==8)&&(a[Y1/40][X1/40+1]==-1))
				  {
					Image1->Canvas->Brush->Color = clRed;
					Image1->Canvas->Rectangle((X1/40+1)*40,(Y1/40)*40,(X1/40+2)*40,(Y1/40+1)*40);
				  }
				 if ((X1/40<8)&&(a[Y1/40][X1/40+1]==-1)&&(a[Y1/40][X1/40+2]!=-1))
				  {
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40+2)*40,(Y1/40)*40,(X1/40+3)*40,(Y1/40+1)*40);
					Image1->Canvas->Brush->Color = clRed;
					Image1->Canvas->Rectangle((X1/40+1)*40,(Y1/40)*40,(X1/40+2)*40,(Y1/40+1)*40);
					if (Y1/40>0)
					{
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40+2)*40,(Y1/40-1)*40,(X1/40+3)*40,(Y1/40)*40);
					}
					if (Y1/40<9)
					{
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40+2)*40,(Y1/40+1)*40,(X1/40+3)*40,(Y1/40+2)*40);
					}
				  }
				 if ((X1/40==7)&&(a[Y1/40][X1/40+1]==-1)&&(a[Y1/40][X1/40+2]==-1))
				 {
				   Image1->Canvas->Brush->Color = clRed;
					Image1->Canvas->Rectangle((X1/40+1)*40,(Y1/40)*40,(X1/40+2)*40,(Y1/40+1)*40);
					Image1->Canvas->Brush->Color = clRed;
					Image1->Canvas->Rectangle((X1/40+2)*40,(Y1/40)*40,(X1/40+3)*40,(Y1/40+1)*40);
					if (Y1/40>0)
					{
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40+2)*40,(Y1/40-1)*40,(X1/40+3)*40,(Y1/40)*40);
					}
					if (Y1/40<9)
					{
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40+2)*40,(Y1/40+1)*40,(X1/40+3)*40,(Y1/40+2)*40);
					}
				 }
				 if ((X1/40<7)&&(a[Y1/40][X1/40+1]==-1)&&(a[Y1/40][X1/40+2]==-1)&&(a[Y1/40][X1/40+3]!=-1))
				  {
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40+3)*40,(Y1/40)*40,(X1/40+4)*40,(Y1/40+1)*40);
					Image1->Canvas->Brush->Color = clRed;
					Image1->Canvas->Rectangle((X1/40+1)*40,(Y1/40)*40,(X1/40+2)*40,(Y1/40+1)*40);
					Image1->Canvas->Rectangle((X1/40+2)*40,(Y1/40)*40,(X1/40+3)*40,(Y1/40+1)*40);
					if (Y1/40>0)
					{
					Image1->Canvas->Brush->Color = clBlue;

					Image1->Canvas->Rectangle((X1/40+2)*40,(Y1/40-1)*40,(X1/40+3)*40,(Y1/40)*40);
					Image1->Canvas->Rectangle((X1/40+3)*40,(Y1/40-1)*40,(X1/40+4)*40,(Y1/40)*40);
					}
					if (Y1/40<9)
					{
					Image1->Canvas->Brush->Color = clBlue;

					Image1->Canvas->Rectangle((X1/40+2)*40,(Y1/40+1)*40,(X1/40+3)*40,(Y1/40+2)*40);
					Image1->Canvas->Rectangle((X1/40+3)*40,(Y1/40+1)*40,(X1/40+4)*40,(Y1/40+2)*40);
					}
				  }
				   if ((X1/40==6)&&(a[Y1/40][X1/40+1]==-1)&&(a[Y1/40][X1/40+2]==-1)&&(a[Y1/40][X1/40+3]==-1))
				 {
				   Image1->Canvas->Brush->Color = clRed;
					Image1->Canvas->Rectangle((X1/40+1)*40,(Y1/40)*40,(X1/40+2)*40,(Y1/40+1)*40);
					Image1->Canvas->Brush->Color = clRed;
					Image1->Canvas->Rectangle((X1/40+2)*40,(Y1/40)*40,(X1/40+3)*40,(Y1/40+1)*40);
					Image1->Canvas->Brush->Color = clRed;
					Image1->Canvas->Rectangle((X1/40+3)*40,(Y1/40)*40,(X1/40+4)*40,(Y1/40+1)*40);
					if (Y1/40>0)
					{
					Image1->Canvas->Brush->Color = clBlue;

					Image1->Canvas->Rectangle((X1/40+2)*40,(Y1/40-1)*40,(X1/40+3)*40,(Y1/40)*40);
					Image1->Canvas->Rectangle((X1/40+3)*40,(Y1/40-1)*40,(X1/40+4)*40,(Y1/40)*40);
					}
					if (Y1/40<9)
					{
					Image1->Canvas->Brush->Color = clBlue;

					Image1->Canvas->Rectangle((X1/40+2)*40,(Y1/40+1)*40,(X1/40+3)*40,(Y1/40+2)*40);
					Image1->Canvas->Rectangle((X1/40+3)*40,(Y1/40+1)*40,(X1/40+4)*40,(Y1/40+2)*40);
					}
				 }
				 if ((X1/40<6)&&(a[Y1/40][X1/40+1]==-1)&&(a[Y1/40][X1/40+2]==-1)&&(a[Y1/40][X1/40+3]==-1)&&(a[Y1/40][X1/40+4]!=-1))
				  {
					Image1->Canvas->Brush->Color = clBlue;
					Image1->Canvas->Rectangle((X1/40+4)*40,(Y1/40)*40,(X1/40+5)*40,(Y1/40+1)*40);
					Image1->Canvas->Brush->Color = clRed;
					Image1->Canvas->Rectangle((X1/40+1)*40,(Y1/40)*40,(X1/40+2)*40,(Y1/40+1)*40);
					Image1->Canvas->Rectangle((X1/40+2)*40,(Y1/40)*40,(X1/40+3)*40,(Y1/40+1)*40);
					Image1->Canvas->Rectangle((X1/40+3)*40,(Y1/40)*40,(X1/40+4)*40,(Y1/40+1)*40);
					if (Y1/40>0)
					{
					Image1->Canvas->Brush->Color = clBlue;

					Image1->Canvas->Rectangle((X1/40+2)*40,(Y1/40-1)*40,(X1/40+3)*40,(Y1/40)*40);
					Image1->Canvas->Rectangle((X1/40+3)*40,(Y1/40-1)*40,(X1/40+4)*40,(Y1/40)*40);
					Image1->Canvas->Rectangle((X1/40+4)*40,(Y1/40-1)*40,(X1/40+5)*40,(Y1/40)*40);
					}
					if (Y1/40<9)
					{
					Image1->Canvas->Brush->Color = clBlue;

					Image1->Canvas->Rectangle((X1/40+2)*40,(Y1/40+1)*40,(X1/40+3)*40,(Y1/40+2)*40);
					Image1->Canvas->Rectangle((X1/40+3)*40,(Y1/40+1)*40,(X1/40+4)*40,(Y1/40+2)*40);
					Image1->Canvas->Rectangle((X1/40+4)*40,(Y1/40+1)*40,(X1/40+5)*40,(Y1/40+2)*40);
					}
				  }
				}
			}
		  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
ch1++;
if (ch1%2==0) {
 Image3->Height=40;
 Image3->Width=160;
 Image3->Canvas->Draw(0,0,k4h);
}
 if (ch1%2==1) {
 Image3->Height=160;
 Image3->Width=40;
 Image3->Canvas->Draw(0,0,k4v);
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
 ch2++;
if (ch2%2==0) {
 Image4->Height=40;
 Image4->Width=120;
 Image4->Canvas->Draw(0,0,k3h);
}
 if (ch2%2==1) {
 Image4->Height=120;
 Image4->Width=40;
 Image4->Canvas->Draw(0,0,k3v);
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn3Click(TObject *Sender)
{
  ch3++;
if (ch3%2==0) {
 Image5->Height=40;
 Image5->Width=80;
 Image5->Canvas->Draw(0,0,k2h);
}
 if (ch3%2==1) {
 Image5->Height=80;
 Image5->Width=40;
 Image5->Canvas->Draw(0,0,k2v);
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image3MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
int xx=X;
int yy=Y;
if ((yy<=40)&&(ch1%2==0))
per=1;
if ((xx<=40)&&(ch1%2==1))
per=2;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TForm1::Image2MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
int xxx=X;
int yyy=Y;
TRect Plocal;
if ((per==1)&&(xxx<280)&&(StrToInt(LabeledEdit1->Text)>0)&&(ch1%2==0)&&(m[yyy/40][xxx/40]*m[yyy/40][xxx/40+1]*m[yyy/40][xxx/40+2]*m[yyy/40][xxx/40+3]==1))
 {
 int check=1;
 if ((xxx>=40)&&(yyy>=40))
 check*=m[yyy/40-1][xxx/40-1];
 if (xxx>=40)
 check*=m[yyy/40][xxx/40-1];
 if ((xxx>=40)&&(yyy<360))
 check*=m[yyy/40+1][xxx/40-1];
 if (yyy>=40)
 {
 check*=m[yyy/40-1][xxx/40];
 check*=m[yyy/40-1][xxx/40+1];
 check*=m[yyy/40-1][xxx/40+2];
 check*=m[yyy/40-1][xxx/40+3];
 }
  if (yyy<360)
 {
 check*=m[yyy/40+1][xxx/40];
 check*=m[yyy/40+1][xxx/40+1];
 check*=m[yyy/40+1][xxx/40+2];
 check*=m[yyy/40+1][xxx/40+3];
 }
 if ((xxx<240)&&(yyy>=40))
 check*=m[yyy/40-1][xxx/40+4];
 if (xxx<240)
 check*=m[yyy/40][xxx/40+4];
 if ((xxx<240)&&(yyy<360))
 check*=m[yyy/40+1][xxx/40+4];

 if (check==1) {
Plocal=Bounds((xxx/40)*40,(yyy/40)*40,160,40);
Image2->Canvas->CopyRect(Plocal,Image3->Canvas,P04h);
per=0;
 LabeledEdit1->Text=IntToStr(StrToInt(LabeledEdit1->Text)-1);
 m[yyy/40][xxx/40]=0;
 m[yyy/40][xxx/40+1]=0;
 m[yyy/40][xxx/40+2]=0;
 m[yyy/40][xxx/40+3]=0;
 got+=4;
 if (got==20)
 Button2->Enabled=True;
 }
}
if ((per==2)&&(yyy<280)&&(StrToInt(LabeledEdit1->Text)>0)&&(ch1%2==1)&&(m[yyy/40][xxx/40]*m[yyy/40+1][xxx/40]*m[yyy/40+2][xxx/40]*m[yyy/40+3][xxx/40]==1))
 {
 int check=1;
 if ((xxx>=40)&&(yyy>=40))
 check*=m[yyy/40-1][xxx/40-1];
 if (yyy>=40)
 check*=m[yyy/40-1][xxx/40];
 if ((yyy>=40)&&(xxx<360))
 check*=m[yyy/40-1][xxx/40+1];
 if (xxx>=40)
 {
 check*=m[yyy/40][xxx/40-1];
 check*=m[yyy/40+1][xxx/40-1];
 check*=m[yyy/40+2][xxx/40-1];
 check*=m[yyy/40+3][xxx/40-1];
 }
  if (xxx<360)
 {
 check*=m[yyy/40][xxx/40+1];
 check*=m[yyy/40+1][xxx/40+1];
 check*=m[yyy/40+2][xxx/40+1];
 check*=m[yyy/40+3][xxx/40+1];
 }
 if ((yyy<240)&&(xxx>=40))
 check*=m[yyy/40+4][xxx/40-1];
 if (yyy<240)
 check*=m[yyy/40+4][xxx/40];
 if ((yyy<240)&&(xxx<360))
 check*=m[yyy/40+4][xxx/40+1];

 if (check==1) {
Plocal=Bounds((xxx/40)*40,(yyy/40)*40,40,160);
Image2->Canvas->CopyRect(Plocal,Image3->Canvas,P04v);
per=0;
 LabeledEdit1->Text=IntToStr(StrToInt(LabeledEdit1->Text)-1);
 m[yyy/40][xxx/40]=0;
 m[yyy/40+1][xxx/40]=0;
 m[yyy/40+2][xxx/40]=0;
 m[yyy/40+3][xxx/40]=0;
 got+=4;
 if (got==20)
 Button2->Enabled=True;
 }
}
if ((per==3)&&(xxx<320)&&(StrToInt(LabeledEdit2->Text)>0)&&(ch2%2==0)&&(m[yyy/40][xxx/40]*m[yyy/40][xxx/40+1]*m[yyy/40][xxx/40+2]==1))
 {
 int check=1;
 if ((xxx>=40)&&(yyy>=40))
 check*=m[yyy/40-1][xxx/40-1];
 if (xxx>=40)
 check*=m[yyy/40][xxx/40-1];
 if ((xxx>=40)&&(yyy<360))
 check*=m[yyy/40+1][xxx/40-1];
 if (yyy>=40)
 {
 check*=m[yyy/40-1][xxx/40];
 check*=m[yyy/40-1][xxx/40+1];
 check*=m[yyy/40-1][xxx/40+2];
 }
  if (yyy<360)
 {
 check*=m[yyy/40+1][xxx/40];
 check*=m[yyy/40+1][xxx/40+1];
 check*=m[yyy/40+1][xxx/40+2];
 }
 if ((xxx<280)&&(yyy>=40))
 check*=m[yyy/40-1][xxx/40+3];
 if (xxx<280)
 check*=m[yyy/40][xxx/40+3];
 if ((xxx<280)&&(yyy<360))
 check*=m[yyy/40+1][xxx/40+3];

 if (check==1) {
Plocal=Bounds((xxx/40)*40,(yyy/40)*40,120,40);
Image2->Canvas->CopyRect(Plocal,Image4->Canvas,P03h);
per=0;
 LabeledEdit2->Text=IntToStr(StrToInt(LabeledEdit2->Text)-1);
 m[yyy/40][xxx/40]=0;
 m[yyy/40][xxx/40+1]=0;
 m[yyy/40][xxx/40+2]=0;
  got+=3;
 if (got==20)
 Button2->Enabled=True;
 }
}
if ((per==4)&&(yyy<320)&&(StrToInt(LabeledEdit2->Text)>0)&&(ch2%2==1)&&(m[yyy/40][xxx/40]*m[yyy/40+1][xxx/40]*m[yyy/40+2][xxx/40]==1))
 {
 int check=1;
 if ((xxx>=40)&&(yyy>=40))
 check*=m[yyy/40-1][xxx/40-1];
 if (yyy>=40)
 check*=m[yyy/40-1][xxx/40];
 if ((yyy>=40)&&(xxx<360))
 check*=m[yyy/40-1][xxx/40+1];
 if (xxx>=40)
 {
 check*=m[yyy/40][xxx/40-1];
 check*=m[yyy/40+1][xxx/40-1];
 check*=m[yyy/40+2][xxx/40-1];
 }
  if (xxx<360)
 {
 check*=m[yyy/40][xxx/40+1];
 check*=m[yyy/40+1][xxx/40+1];
 check*=m[yyy/40+2][xxx/40+1];
 }
 if ((yyy<280)&&(xxx>=40))
 check*=m[yyy/40+3][xxx/40-1];
 if (yyy<280)
 check*=m[yyy/40+3][xxx/40];
 if ((yyy<280)&&(xxx<360))
 check*=m[yyy/40+3][xxx/40+1];

 if (check==1) {
Plocal=Bounds((xxx/40)*40,(yyy/40)*40,40,120);
Image2->Canvas->CopyRect(Plocal,Image4->Canvas,P03v);
per=0;
 LabeledEdit2->Text=IntToStr(StrToInt(LabeledEdit2->Text)-1);
 m[yyy/40][xxx/40]=0;
 m[yyy/40+1][xxx/40]=0;
 m[yyy/40+2][xxx/40]=0;
  got+=3;
 if (got==20)
 Button2->Enabled=True;
 }
}
if ((per==5)&&(xxx<360)&&(StrToInt(LabeledEdit3->Text)>0)&&(ch3%2==0)&&(m[yyy/40][xxx/40]*m[yyy/40][xxx/40+1]==1))
 {
 int check=1;
 if ((xxx>=40)&&(yyy>=40))
 check*=m[yyy/40-1][xxx/40-1];
 if (xxx>=40)
 check*=m[yyy/40][xxx/40-1];
 if ((xxx>=40)&&(yyy<360))
 check*=m[yyy/40+1][xxx/40-1];
 if (yyy>=40)
 {
 check*=m[yyy/40-1][xxx/40];
 check*=m[yyy/40-1][xxx/40+1];
 }
  if (yyy<360)
 {
 check*=m[yyy/40+1][xxx/40];
 check*=m[yyy/40+1][xxx/40+1];
 }
 if ((xxx<320)&&(yyy>=40))
 check*=m[yyy/40-1][xxx/40+2];
 if (xxx<320)
 check*=m[yyy/40][xxx/40+2];
 if ((xxx<320)&&(yyy<360))
 check*=m[yyy/40+1][xxx/40+2];

 if (check==1) {
Plocal=Bounds((xxx/40)*40,(yyy/40)*40,80,40);
Image2->Canvas->CopyRect(Plocal,Image5->Canvas,P02h);
per=0;
 LabeledEdit3->Text=IntToStr(StrToInt(LabeledEdit3->Text)-1);
 m[yyy/40][xxx/40]=0;
 m[yyy/40][xxx/40+1]=0;
  got+=2;
 if (got==20)
 Button2->Enabled=True;
 }
}
if ((per==6)&&(yyy<360)&&(StrToInt(LabeledEdit3->Text)>0)&&(ch3%2==1)&&(m[yyy/40][xxx/40]*m[yyy/40+1][xxx/40]==1))
 {
 int check=1;
 if ((xxx>=40)&&(yyy>=40))
 check*=m[yyy/40-1][xxx/40-1];
 if (yyy>=40)
 check*=m[yyy/40-1][xxx/40];
 if ((yyy>=40)&&(xxx<360))
 check*=m[yyy/40-1][xxx/40+1];
 if (xxx>=40)
 {
 check*=m[yyy/40][xxx/40-1];
 check*=m[yyy/40+1][xxx/40-1];
 }
  if (xxx<360)
 {
 check*=m[yyy/40][xxx/40+1];
 check*=m[yyy/40+1][xxx/40+1];
 }
 if ((yyy<320)&&(xxx>=40))
 check*=m[yyy/40+2][xxx/40-1];
 if (yyy<320)
 check*=m[yyy/40+2][xxx/40];
 if ((yyy<320)&&(xxx<360))
 check*=m[yyy/40+2][xxx/40+1];

 if (check==1) {
Plocal=Bounds((xxx/40)*40,(yyy/40)*40,40,80);
Image2->Canvas->CopyRect(Plocal,Image5->Canvas,P02v);
per=0;
 LabeledEdit3->Text=IntToStr(StrToInt(LabeledEdit3->Text)-1);
 m[yyy/40][xxx/40]=0;
 m[yyy/40+1][xxx/40]=0;
  got+=2;
 if (got==20)
 Button2->Enabled=True;
 }
}
if ((per==7)&&(StrToInt(LabeledEdit4->Text)>0)&&(m[yyy/40][xxx/40]==1))
 {
 int check=1;
 if ((xxx>=40)&&(yyy>=40))
 check*=m[yyy/40-1][xxx/40-1];
 if (xxx>=40)
 check*=m[yyy/40][xxx/40-1];
 if ((xxx>=40)&&(yyy<360))
 check*=m[yyy/40+1][xxx/40-1];
 if (yyy>=40)
 check*=m[yyy/40-1][xxx/40];
  if (yyy<360)
 check*=m[yyy/40+1][xxx/40];
 if ((xxx<360)&&(yyy>=40))
 check*=m[yyy/40-1][xxx/40+1];
 if (xxx<360)
 check*=m[yyy/40][xxx/40+1];
 if ((xxx<360)&&(yyy<360))
 check*=m[yyy/40+1][xxx/40+1];

 if (check==1) {
Plocal=Bounds((xxx/40)*40,(yyy/40)*40,40,40);
Image2->Canvas->CopyRect(Plocal,Image6->Canvas,P01);
per=0;
 LabeledEdit4->Text=IntToStr(StrToInt(LabeledEdit4->Text)-1);
 m[yyy/40][xxx/40]=0;
  got++;
 if (got==20)
 Button2->Enabled=True;
 }
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image4MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
   int xx=X;
int yy=Y;
if ((yy<=40)&&(ch2%2==0))
per=3;
if ((xx<=40)&&(ch2%2==1))
per=4;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image5MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
  int xx=X;
int yy=Y;
if ((yy<=40)&&(ch3%2==0))
per=5;
if ((xx<=40)&&(ch3%2==1))
per=6;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image6MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
per=7;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
 gotovo=1;
Button2->Visible=False;
Label2->Caption="Расставьте корабли соперника";
LabeledEdit1->Visible=False;
LabeledEdit2->Visible=False;
LabeledEdit3->Visible=False;
LabeledEdit4->Visible=False;
Image3->Visible=False;
Image4->Visible=False;
Image5->Visible=False;
Image6->Visible=False;
BitBtn1->Visible=False;
BitBtn2->Visible=False;
BitBtn3->Visible=False;
 for (int i = 0; i < 10; i++)
 for (int j = 0; j< 10; j++)
  c[i][j]=m[i][j];
 }
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
if (end==0)
{
int don=0;
 while (don==0)
 {
   if (level==0)
  ra=rand()%100;
  if (level==3) {
	  int dan=0;
	  while (dan==0)
		  {
			  tyk=rand()%2;
			  ra=ad3[tyk];
			  if ((c[ra/10][ra%10]!=-1)&&(ad3[tyk]!=-1))
			dan=1;
		  }
		if (tyk==0)
		level=0;
  }
  if (level==2) {
	  int dan=0;
	  while (dan==0)
	  {
		  tyk=rand()%2;
		  ra=ad2[tyk];
		  if ((c[ra/10][ra%10]!=-1)&&(ad2[tyk]!=-1))
		dan=1;
	  }
	  if ((tyk==0)&&(situ>4)&&(situ<11))
	  level=0;
	  if ((tyk==0)&&((((situ==11)||(situ==14))||((situ==15)||(situ==18)))||((((situ==12)&&(si==1))||((situ==13)&&(si==2)))||(((situ==16)&&(si==3))||((situ==17)&&(si==4))))))
	  level=3;
	  if ((tyk==0)&&(situ==12)&&(si==5))
	   {
	   level=3;
	   ad3[0]=ra+3;
	   ad3[1]=ra-1;
	   if (ra%10==0)
		ad3[1]=-1;
	   }
	   if ((tyk==1)&&(situ==12)&&(si==5))
	   {
	   level=3;
	   ad3[0]=ra-3;
	   ad3[1]=ra+1;
	   if (ra%10==9)
		ad3[1]=-1;
	   }
	   if ((tyk==0)&&(situ==13)&&(si==6))
	   {
	   level=3;
	   ad3[0]=ra+3;
	   ad3[1]=ra-1;
	   if (ra%10==0)
		ad3[1]=-1;
	   }
	   if ((tyk==1)&&(situ==13)&&(si==6))
	   {
	   level=3;
	   ad3[0]=ra-3;
	   ad3[1]=ra+1;
	   if (ra%10==9)
		ad3[1]=-1;
	   }
	   if ((tyk==0)&&(situ==16)&&(si==7))
	   {
	   level=3;
	   ad3[0]=ra+30;
	   ad3[1]=ra-10;
	   if (ra/10==0)
		ad3[1]=-1;
	   }
	   if ((tyk==1)&&(situ==16)&&(si==7))
	   {
	   level=3;
	   ad3[0]=ra-30;
	   ad3[1]=ra+10;
	   if (ra/10==9)
		ad3[1]=-1;
	   }
	   if ((tyk==0)&&(situ==17)&&(si==8))
	   {
	   level=3;
	   ad3[0]=ra+30;
	   ad3[1]=ra-10;
	   if (ra/10==0)
		ad3[1]=-1;
	   }
	   if ((tyk==1)&&(situ==17)&&(si==8))
	   {
	   level=3;
	   ad3[0]=ra-30;
	   ad3[1]=ra+10;
	   if (ra/10==9)
		ad3[1]=-1;
	   }
  }
  if (level==1) {
	  int dan=0;
	  while (dan==0)
		{
	  tyk=rand()%4;
	  ra=ad1[tyk];
	  if ((c[ra/10][ra%10]!=-1)&&(ad1[tyk]!=-1))
		dan=1;
		}
	  if ((tyk==0)&&(situ>0)&&(situ<5))
	   level=0;
	   if ((tyk==0)&&(situ>4)&&(situ<9))
	   level=2;
	   if ((tyk==0)&&(((situ==11)||(situ==14))||((situ==15)||(situ==18))))
	   level=2;
	   if ((tyk==0)&&(situ==9))
	   {
	   level=2;
	   ad2[0]=ra+2;
	   ad2[1]=ra-1;
	   if (ra%10==0)
		ad2[1]=-1;
	   }
	   if ((tyk==1)&&(situ==9))
	   {
	   level=2;
	   ad2[0]=ra-2;
	   ad2[1]=ra+1;
	   if (ra%10==9)
		ad2[1]=-1;
	   }
	   if ((tyk==0)&&(situ==10))
	   {
	   level=2;
	   ad2[0]=ra+20;
	   ad2[1]=ra-10;
	   if (ra/10==0)
		ad2[1]=-1;
	   }
	   if ((tyk==1)&&(situ==10))
	   {
	   level=2;
	   ad2[0]=ra-20;
	   ad2[1]=ra+10;
	   if (ra/10==9)
		ad2[1]=-1;
	   }
	   if ((tyk==0)&&(situ==12))
	   {
	   level=2;
	   si=1;
	   ad2[0]=ra+2;
	   ad2[1]=ra-1;
	   if (ra%10==0)
		ad2[1]=-1;
	   ad3[0]=ra+3;
	   ad3[1]=ra-1;
	   if (ra%10==0)
		ad3[1]=-1;
	   }
	   if ((tyk==1)&&(situ==12))
	   {
	   level=2;
	   si=5;
	   ad2[0]=ra-2;
	   ad2[1]=ra+1;
	   }
	   if ((tyk==0)&&(situ==13))
	   {
	   level=2;
	   si=6;
	   ad2[0]=ra-1;
	   ad2[1]=ra+2;
	   }
	   if ((tyk==1)&&(situ==13))
	   {
	   level=2;
	   si=2;
	   ad2[0]=ra-2;
	   ad2[1]=ra+1;
	   if (ra%10==9)
		ad2[1]=-1;
	   ad3[0]=ra-3;
	   ad3[1]=ra+1;
	   if (ra%10==9)
		ad3[1]=-1;
	   }
	   if ((tyk==0)&&(situ==16))
	   {
	   level=2;
	   si=3;
	   ad2[0]=ra+20;
	   ad2[1]=ra-10;
	   if (ra/10==0)
		ad2[1]=-1;
	   ad3[0]=ra+30;
	   ad3[1]=ra-10;
	   if (ra/10==0)
		ad3[1]=-1;
	   }
	   if ((tyk==1)&&(situ==16))
	   {
	   level=2;
	   si=7;
	   ad2[0]=ra-20;
	   ad2[1]=ra+10;
	   }
	   if ((tyk==0)&&(situ==17))
	   {
	   level=2;
	   si=8;
	   ad2[0]=ra-10;
	   ad2[1]=ra+20;
	   }
	   if ((tyk==1)&&(situ==17))
	   {
	   level=2;
	   si=4;
	   ad2[0]=ra-20;
	   ad2[1]=ra+10;
	   if (ra/10==9)
		ad2[1]=-1;
	   ad3[0]=ra-30;
	   ad3[1]=ra+10;
	   if (ra/10==9)
		ad3[1]=-1;
	   }
  }
  if (c[ra/10][ra%10]==1) {
   c[ra/10][ra%10]=-1;
   Image2->Canvas->Brush->Color = clBlue;
   Image2->Canvas->Rectangle((ra%10)*40,(ra/10)*40,(ra%10+1)*40,(ra/10+1)*40);
   hod=0;
   don=1;
   Timer1->Enabled=False;
  }
  if (c[ra/10][ra%10]==0) {
   c[ra/10][ra%10]=-2;
   cwin++;
	Image2->Canvas->Draw((ra%10)*40,(ra/10)*40,krest);
	int pro=1;
			if ((ra/10>0)&&(c[ra/10-1][ra%10]==0))
				pro=0;
			if ((ra/10>1)&&(c[ra/10-1][ra%10]==-2)&&(c[ra/10-2][ra%10]==0))
				pro=0;
			if ((ra/10>2)&&(c[ra/10-1][ra%10]==-2)&&(c[ra/10-2][ra%10]==-2)&&(c[ra/10-3][ra%10]==0))
				pro=0;

			 if ((ra/10<9)&&(c[ra/10+1][ra%10]==0))
				pro=0;
			if ((ra/10<8)&&(c[ra/10+1][ra%10]==-2)&&(c[ra/10+2][ra%10]==0))
				pro=0;
			if ((ra/10<7)&&(c[ra/10+1][ra%10]==-2)&&(c[ra/10+2][ra%10]==-2)&&(c[ra/10+3][ra%10]==0))
				pro=0;

			if ((ra%10>0)&&(c[ra/10][ra%10-1]==0))
				pro=0;
			if ((ra%10>1)&&(c[ra/10][ra%10-1]==-2)&&(c[ra/10][ra%10-2]==0))
				pro=0;
			if ((ra%10>2)&&(c[ra/10][ra%10-1]==-2)&&(c[ra/10][ra%10-2]==-2)&&(c[ra/10][ra%10-3]==0))
				pro=0;

			if ((ra%10<9)&&(c[ra/10][ra%10+1]==0))
				pro=0;
			if ((ra%10<8)&&(c[ra/10][ra%10+1]==-2)&&(c[ra/10][ra%10+2]==0))
				pro=0;
			if ((ra%10<7)&&(c[ra/10][ra%10+1]==-2)&&(c[ra/10][ra%10+2]==-2)&&(c[ra/10][ra%10+3]==0))
				pro=0;

				if ((pro==0)&&(level==0)) {
				  if (((c[ra/10-1][ra%10]*c[ra/10-1][ra%10]==1)||(ra/10==0))&&((c[ra/10][ra%10-1]*c[ra/10][ra%10-1]==1)||(ra%10==0))&&((c[ra/10][ra%10+1]*c[ra/10][ra%10+1]==1)||(ra%10==9))&&((c[ra/10+2][ra%10]*c[ra/10+2][ra%10]==1)||(ra/10==8))&&(c[ra/10+1][ra%10]==0)) {

					  situ=1;
					  ad1[0]=ra+10;
					  ad1[1]=ra-1;
					  if (ra%10==0)
					   ad1[1]=-1;
					  ad1[2]=ra+1;
					  if (ra%10==9)
					   ad1[2]=-1;
					  ad1[3]=ra-10;
					  if (ra/10==0)
					   ad1[3]=-1;
					  level=1;
					}
				  if (((c[ra/10+1][ra%10]*c[ra/10+1][ra%10]==1)||(ra/10==9))&&((c[ra/10][ra%10-1]*c[ra/10][ra%10-1]==1)||(ra%10==0))&&((c[ra/10][ra%10+1]*c[ra/10][ra%10+1]==1)||(ra%10==9))&&((c[ra/10-2][ra%10]*c[ra/10-2][ra%10]==1)||(ra/10==1))&&(c[ra/10-1][ra%10]==0)) {

					  situ=2;
					  ad1[0]=ra-10;
					  ad1[1]=ra-1;
					  if (ra%10==0)
					   ad1[1]=-1;
					  ad1[2]=ra+1;
					  if (ra%10==9)
					   ad1[2]=-1;
					  ad1[3]=ra+10;
					  if (ra/10==9)
					   ad1[3]=-1;
					  level=1;
					}
				   if (((c[ra/10+1][ra%10]*c[ra/10+1][ra%10]==1)||(ra/10==9))&&((c[ra/10][ra%10-1]*c[ra/10][ra%10-1]==1)||(ra%10==0))&&((c[ra/10][ra%10+2]*c[ra/10][ra%10+2]==1)||(ra%10==8))&&((c[ra/10-1][ra%10]*c[ra/10-1][ra%10]==1)||(ra/10==0))&&(c[ra/10][ra%10+1]==0)) {

					  situ=3;
					  ad1[0]=ra+1;
					  ad1[1]=ra-1;
                      if (ra%10==0)
					   ad1[1]=-1;
					  ad1[2]=ra-10;
					  if (ra/10==0)
					   ad1[2]=-1;
					  ad1[3]=ra+10;
					  if (ra/10==9)
					   ad1[3]=-1;
					  level=1;
					}
				   if (((c[ra/10+1][ra%10]*c[ra/10+1][ra%10]==1)||(ra/10==9))&&((c[ra/10][ra%10-2]*c[ra/10][ra%10-2]==1)||(ra%10==1))&&((c[ra/10][ra%10+1]*c[ra/10][ra%10+1]==1)||(ra%10==9))&&((c[ra/10-1][ra%10]*c[ra/10-1][ra%10]==1)||(ra/10==0))&&(c[ra/10][ra%10-1]==0)) {
					  situ=4;
					  ad1[0]=ra-1;
					  ad1[1]=ra+1;
					  if (ra%10==9)
					   ad1[1]=-1;
					  ad1[2]=ra-10;
					  if (ra/10==0)
					   ad1[2]=-1;
					  ad1[3]=ra+10;
					  if (ra/10==9)
					   ad1[3]=-1;
					  level=1;
					}
				   if (((c[ra/10+3][ra%10]*c[ra/10+3][ra%10]==1)||(ra/10==7))&&((c[ra/10][ra%10-1]*c[ra/10][ra%10-1]==1)||(ra%10==0))&&((c[ra/10][ra%10+1]*c[ra/10][ra%10+1]==1)||(ra%10==9))&&((c[ra/10-1][ra%10]*c[ra/10-1][ra%10]==1)||(ra/10==0))&&(c[ra/10+1][ra%10]==0)&&(c[ra/10+2][ra%10]==0)&&(ra/10<8)) {
					  situ=5;
					  ad1[0]=ra+10;
					  ad1[1]=ra+1;
					  if (ra%10==9)
					   ad1[1]=-1;
					  ad1[2]=ra-10;
					  if (ra/10==0)
					   ad1[2]=-1;
					  ad1[3]=ra-1;
					  if (ra%10==0)
					   ad1[3]=-1;
					  ad2[0]=ra+20;
					  ad2[1]=ra-10;
					  if (ra/10==0)
					   ad2[1]=-1;
					  level=1;
					}
				   if (((c[ra/10+1][ra%10]*c[ra/10+1][ra%10]==1)||(ra/10==9))&&((c[ra/10][ra%10-1]*c[ra/10][ra%10-1]==1)||(ra%10==0))&&((c[ra/10][ra%10+1]*c[ra/10][ra%10+1]==1)||(ra%10==9))&&((c[ra/10-3][ra%10]*c[ra/10-3][ra%10]==1)||(ra/10==2))&&(c[ra/10-1][ra%10]==0)&&(c[ra/10-2][ra%10]==0)&&(ra/10>1)) {
					  situ=6;
					  ad1[0]=ra-10;
					  ad1[1]=ra+1;
					  if (ra%10==9)
					   ad1[1]=-1;
					  ad1[2]=ra+10;
					  if (ra/10==9)
					   ad1[2]=-1;
					  ad1[3]=ra-1;
					  if (ra%10==0)
					   ad1[3]=-1;
					  ad2[0]=ra-20;
					  ad2[1]=ra+10;
					  if (ra/10==9)
					   ad2[1]=-1;
					  level=1;
					}
				   if (((c[ra/10+1][ra%10]*c[ra/10+1][ra%10]==1)||(ra/10==9))&&((c[ra/10][ra%10-1]*c[ra/10][ra%10-1]==1)||(ra%10==0))&&((c[ra/10][ra%10+3]*c[ra/10][ra%10+3]==1)||(ra%10==7))&&((c[ra/10-1][ra%10]*c[ra/10-1][ra%10]==1)||(ra/10==0))&&(c[ra/10][ra%10+1]==0)&&(c[ra/10][ra%10+2]==0)&&(ra%10<8)) {
					  situ=7;
					  ad1[0]=ra+1;
					  ad1[1]=ra-10;
					  if (ra/10==0)
					   ad1[1]=-1;
					  ad1[2]=ra+10;
					  if (ra/10==9)
					   ad1[2]=-1;
					  ad1[3]=ra-1;
					  if (ra%10==0)
					   ad1[3]=-1;
					  ad2[0]=ra+2;
					  ad2[1]=ra-1;
					  if (ra%10==0)
					   ad2[1]=-1;
					  level=1;
					}
				   if (((c[ra/10+1][ra%10]*c[ra/10+1][ra%10]==1)||(ra/10==9))&&((c[ra/10][ra%10-3]*c[ra/10][ra%10-3]==1)||(ra%10==2))&&((c[ra/10][ra%10+1]*c[ra/10][ra%10+1]==1)||(ra%10==9))&&((c[ra/10-1][ra%10]*c[ra/10-1][ra%10]==1)||(ra/10==0))&&(c[ra/10][ra%10-1]==0)&&(c[ra/10][ra%10-2]==0)&&(ra%10>1)) {
					  situ=8;
					  ad1[0]=ra-1;
					  ad1[1]=ra-10;
					  if (ra/10==0)
					   ad1[1]=-1;
					  ad1[2]=ra+10;
					  if (ra/10==9)
					   ad1[2]=-1;
					  ad1[3]=ra+1;
					  if (ra%10==9)
					   ad1[3]=-1;
					  ad2[0]=ra-2;
					  ad2[1]=ra+1;
					  if (ra%10==9)
					   ad2[1]=-1;
					  level=1;
					}
				   if (((c[ra/10+1][ra%10]*c[ra/10+1][ra%10]==1)||(ra/10==9))&&((c[ra/10][ra%10-2]*c[ra/10][ra%10-2]==1)||(ra%10==1))&&((c[ra/10][ra%10+2]*c[ra/10][ra%10+2]==1)||(ra%10==8))&&((c[ra/10-1][ra%10]*c[ra/10-1][ra%10]==1)||(ra/10==0))&&(c[ra/10][ra%10-1]==0)&&(c[ra/10][ra%10+1]==0)&&(ra%10>0)&&(ra%10<9)) {
					  situ=9;
					  ad1[0]=ra-1;
					  ad1[1]=ra+1;
					  if (ra%10==9)
					   ad1[1]=-1;
					  ad1[2]=ra+10;
					  if (ra/10==9)
					   ad1[2]=-1;
					  ad1[3]=ra-10;
					  if (ra/10==0)
					   ad1[3]=-1;
					  level=1;
					}
				   if (((c[ra/10+2][ra%10]*c[ra/10+2][ra%10]==1)||(ra/10==8))&&((c[ra/10][ra%10-1]*c[ra/10][ra%10-1]==1)||(ra%10==0))&&((c[ra/10][ra%10+1]*c[ra/10][ra%10+1]==1)||(ra%10==9))&&((c[ra/10-2][ra%10]*c[ra/10-2][ra%10]==1)||(ra/10==1))&&(c[ra/10-1][ra%10]==0)&&(c[ra/10+1][ra%10]==0)&&(ra/10>0)&&(ra/10<9)) {
					  situ=10;
					  ad1[0]=ra-10;
					  ad1[1]=ra+10;
					  if (ra/10==9)
					   ad1[1]=-1;
					  ad1[2]=ra+1;
					  if (ra%10==9)
					   ad1[2]=-1;
					  ad1[3]=ra-1;
					  if (ra%10==0)
					   ad1[3]=-1;
					  level=1;
					}
				   if (((c[ra/10+1][ra%10]*c[ra/10+1][ra%10]==1)||(ra/10==9))&&((c[ra/10][ra%10-1]*c[ra/10][ra%10-1]==1)||(ra%10==0))&&((c[ra/10][ra%10+4]*c[ra/10][ra%10+4]==1)||(ra%10==6))&&((c[ra/10-1][ra%10]*c[ra/10-1][ra%10]==1)||(ra/10==0))&&(c[ra/10][ra%10+1]==0)&&(c[ra/10][ra%10+2]==0)&&(c[ra/10][ra%10+3]==0)&&(ra%10<7)) {
					  situ=11;
					  ad1[0]=ra+1;
					  ad1[1]=ra-10;
					  if (ra/10==0)
					   ad1[1]=-1;
					  ad1[2]=ra+10;
					  if (ra/10==9)
					   ad1[2]=-1;
					  ad1[3]=ra-1;
					  if (ra%10==0)
					   ad1[3]=-1;
					  ad2[0]=ra+2;
					  ad2[1]=ra-1;
					  if (ra%10==0)
					   ad2[1]=-1;
					  ad3[0]=ra+3;
					  ad3[1]=ra-1;
					  if (ra%10==0)
					   ad3[1]=-1;
					  level=1;
					}
				   if (((c[ra/10+1][ra%10]*c[ra/10+1][ra%10]==1)||(ra/10==9))&&((c[ra/10][ra%10-2]*c[ra/10][ra%10-2]==1)||(ra%10==1))&&((c[ra/10][ra%10+3]*c[ra/10][ra%10+3]==1)||(ra%10==7))&&((c[ra/10-1][ra%10]*c[ra/10-1][ra%10]==1)||(ra/10==0))&&(c[ra/10][ra%10-1]==0)&&(c[ra/10][ra%10+1]==0)&&(c[ra/10][ra%10+2]==0)&&(ra%10>0)&&(ra%10<8)) {
					  situ=12;
					  ad1[0]=ra-1;
					  ad1[1]=ra+1;
					  ad1[2]=ra+10;
					  if (ra/10==9)
					   ad1[2]=-1;
					  ad1[3]=ra-10;
					  if (ra/10==0)
					   ad1[3]=-1;
					  level=1;
					}
				   if (((c[ra/10+1][ra%10]*c[ra/10+1][ra%10]==1)||(ra/10==9))&&((c[ra/10][ra%10-3]*c[ra/10][ra%10-3]==1)||(ra%10==2))&&((c[ra/10][ra%10+2]*c[ra/10][ra%10+2]==1)||(ra%10==8))&&((c[ra/10-1][ra%10]*c[ra/10-1][ra%10]==1)||(ra/10==0))&&(c[ra/10][ra%10-1]==0)&&(c[ra/10][ra%10+1]==0)&&(c[ra/10][ra%10-2]==0)&&(ra%10>1)&&(ra%10<9)) {
					  situ=13;
					  ad1[0]=ra-1;
					  ad1[1]=ra+1;
					  ad1[2]=ra+10;
					  if (ra/10==9)
					   ad1[2]=-1;
					  ad1[3]=ra-10;
					  if (ra/10==0)
					   ad1[3]=-1;
					  level=1;
					}
				   if (((c[ra/10+1][ra%10]*c[ra/10+1][ra%10]==1)||(ra/10==9))&&((c[ra/10][ra%10-4]*c[ra/10][ra%10-4]==1)||(ra%10==3))&&((c[ra/10][ra%10+1]*c[ra/10][ra%10+1]==1)||(ra%10==9))&&((c[ra/10-1][ra%10]*c[ra/10-1][ra%10]==1)||(ra/10==0))&&(c[ra/10][ra%10-1]==0)&&(c[ra/10][ra%10-2]==0)&&(c[ra/10][ra%10-3]==0)&&(ra%10>2)) {
					  situ=14;
					  ad1[0]=ra-1;
					  ad1[1]=ra-10;
					  if (ra/10==0)
					   ad1[1]=-1;
					  ad1[2]=ra+10;
					  if (ra/10==9)
					   ad1[2]=-1;
					  ad1[3]=ra+1;
					  if (ra%10==9)
					   ad1[3]=-1;
					  ad2[0]=ra-2;
					  ad2[1]=ra+1;
					  if (ra%10==9)
					   ad2[1]=-1;
					  ad3[0]=ra-3;
					  ad3[1]=ra+1;
					  if (ra%10==9)
					   ad3[1]=-1;
					  level=1;
					}
				   if (((c[ra/10+4][ra%10]*c[ra/10+4][ra%10]==1)||(ra/10==6))&&((c[ra/10][ra%10-1]*c[ra/10][ra%10-1]==1)||(ra%10==0))&&((c[ra/10][ra%10+1]*c[ra/10][ra%10+1]==1)||(ra%10==9))&&((c[ra/10-1][ra%10]*c[ra/10-1][ra%10]==1)||(ra/10==0))&&(c[ra/10+1][ra%10]==0)&&(c[ra/10+2][ra%10]==0)&&(c[ra/10+3][ra%10]==0)&&(ra/10<7)) {
					  situ=15;
					  ad1[0]=ra+10;
					  ad1[1]=ra+1;
					  if (ra%10==9)
					   ad1[1]=-1;
					  ad1[2]=ra-10;
					  if (ra/10==0)
					   ad1[2]=-1;
					  ad1[3]=ra-1;
					  if (ra%10==0)
					   ad1[3]=-1;
					  ad2[0]=ra+20;
					  ad2[1]=ra-10;
					  if (ra/10==0)
					   ad2[1]=-1;
					  ad3[0]=ra+30;
					  ad3[1]=ra-10;
					  if (ra/10==0)
					   ad3[1]=-1;
					  level=1;
					}
				   if (((c[ra/10+3][ra%10]*c[ra/10+3][ra%10]==1)||(ra/10==7))&&((c[ra/10][ra%10-1]*c[ra/10][ra%10-1]==1)||(ra%10==0))&&((c[ra/10][ra%10+1]*c[ra/10][ra%10+1]==1)||(ra%10==9))&&((c[ra/10-2][ra%10]*c[ra/10-2][ra%10]==1)||(ra/10==1))&&(c[ra/10-1][ra%10]==0)&&(c[ra/10+1][ra%10]==0)&&(c[ra/10+2][ra%10]==0)&&(ra/10>0)&&(ra/10<8)) {
					  situ=16;
					  ad1[0]=ra-10;
					  ad1[1]=ra+10;
					  ad1[2]=ra+1;
					  if (ra%10==9)
					   ad1[2]=-1;
					  ad1[3]=ra-1;
					  if (ra%10==0)
					   ad1[3]=-1;
					  level=1;
					}
				   if (((c[ra/10+2][ra%10]*c[ra/10+2][ra%10]==1)||(ra/10==8))&&((c[ra/10][ra%10-1]*c[ra/10][ra%10-1]==1)||(ra%10==0))&&((c[ra/10][ra%10+1]*c[ra/10][ra%10+1]==1)||(ra%10==9))&&((c[ra/10-3][ra%10]*c[ra/10-3][ra%10]==1)||(ra/10==2))&&(c[ra/10-1][ra%10]==0)&&(c[ra/10+1][ra%10]==0)&&(c[ra/10-2][ra%10]==0)&&(ra/10>1)&&(ra/10<9)) {
					  situ=17;
					  ad1[0]=ra-10;
					  ad1[1]=ra+10;
					  ad1[2]=ra+1;
					  if (ra%10==9)
					   ad1[2]=-1;
					  ad1[3]=ra-1;
					  if (ra%10==0)
					   ad1[3]=-1;
					  level=1;
					}
				   if (((c[ra/10+1][ra%10]*c[ra/10+1][ra%10]==1)||(ra/10==9))&&((c[ra/10][ra%10-1]*c[ra/10][ra%10-1]==1)||(ra%10==0))&&((c[ra/10][ra%10+1]*c[ra/10][ra%10+1]==1)||(ra%10==9))&&((c[ra/10-4][ra%10]*c[ra/10-4][ra%10]==1)||(ra/10==3))&&(c[ra/10-1][ra%10]==0)&&(c[ra/10-2][ra%10]==0)&&(c[ra/10-3][ra%10]==0)&&(ra/10>2)) {
					  situ=18;
					  ad1[0]=ra-10;
					  ad1[1]=ra+1;
					  if (ra%10==9)
					   ad1[1]=-1;
					  ad1[2]=ra+10;
					  if (ra/10==9)
					   ad1[2]=-1;
					  ad1[3]=ra-1;
					  if (ra%10==0)
					   ad1[3]=-1;
					  ad2[0]=ra-20;
					  ad2[1]=ra+10;
					  if (ra/10==9)
					   ad2[1]=-1;
					  ad3[0]=ra-30;
					  ad3[1]=ra+10;
					  if (ra/10==9)
					   ad3[1]=-1;
					  level=1;
					}
				}
					if (pro==1) {
			  if ((ra%10>0)&&(ra/10>0)) {
			  Image2->Canvas->Brush->Color = clBlue;
			 Image2->Canvas->Rectangle((ra%10-1)*40,(ra/10-1)*40,(ra%10)*40,(ra/10)*40);
			 c[ra/10-1][ra%10-1]=-1;
			 }
			  if ((ra%10>0)&&(ra/10<9)) {
			  Image2->Canvas->Brush->Color = clBlue;
			 Image2->Canvas->Rectangle((ra%10-1)*40,(ra/10+1)*40,(ra%10)*40,(ra/10+2)*40);
			 c[ra/10+1][ra%10-1]=-1;
			 }
			 if ((ra%10<9)&&(ra/10<9)) {
			  Image2->Canvas->Brush->Color = clBlue;
			 Image2->Canvas->Rectangle((ra%10+1)*40,(ra/10+1)*40,(ra%10+2)*40,(ra/10+2)*40);
			 c[ra/10+1][ra%10+1]=-1;
			 }
			 if ((ra%10<9)&&(ra/10>0)) {
			  Image2->Canvas->Brush->Color = clBlue;
			 Image2->Canvas->Rectangle((ra%10+1)*40,(ra/10-1)*40,(ra%10+2)*40,(ra/10)*40);
			 c[ra/10-1][ra%10+1]=-1;
			 }
				if ((ra/10>0)&&(c[ra/10-1][ra%10]!=-2))
				  {
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10)*40,(ra/10-1)*40,(ra%10+1)*40,(ra/10)*40);
					c[ra/10-1][ra%10]=-1;
				  }
				  if ((ra/10==1)&&(c[ra/10-1][ra%10]==-2))
				  {
					Image2->Canvas->Brush->Color = clBlue;
					if (ra%10>0){
					Image2->Canvas->Rectangle((ra%10-1)*40,(ra/10)*40,(ra%10)*40,(ra/10+1)*40);
					c[ra/10][ra%10-1]=-1;
					}
					if (ra%10<9) {
					Image2->Canvas->Rectangle((ra%10+1)*40,(ra/10)*40,(ra%10+2)*40,(ra/10+1)*40);
					c[ra/10][ra%10+1]=-1;
					}
				  }
				 if ((ra/10>1)&&(c[ra/10-1][ra%10]==-2)&&(c[ra/10-2][ra%10]!=-2))
				  {
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10)*40,(ra/10-2)*40,(ra%10+1)*40,(ra/10-1)*40);
					c[ra/10-2][ra%10]=-1;
				  if (ra%10>0)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10-1)*40,(ra/10)*40,(ra%10)*40,(ra/10+1)*40);
					c[ra/10][ra%10-1]=-1;
					Image2->Canvas->Rectangle((ra%10-1)*40,(ra/10-2)*40,(ra%10)*40,(ra/10-1)*40);
					c[ra/10-2][ra%10-1]=-1;
					}
					if (ra%10<9)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10+1)*40,(ra/10)*40,(ra%10+2)*40,(ra/10+1)*40);
					c[ra/10][ra%10+1]=-1;
					Image2->Canvas->Rectangle((ra%10+1)*40,(ra/10-2)*40,(ra%10+2)*40,(ra/10-1)*40);
					c[ra/10-2][ra%10+1]=-1;
					}
				  }
				 if ((ra/10==2)&&(c[ra/10-1][ra%10]==-2)&&(c[ra/10-2][ra%10]==-2))
				 {
					if (ra%10>0)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10-1)*40,(ra/10)*40,(ra%10)*40,(ra/10+1)*40);
					c[ra/10][ra%10-1]=-1;
					Image2->Canvas->Rectangle((ra%10-1)*40,(ra/10-2)*40,(ra%10)*40,(ra/10-1)*40);
					c[ra/10-2][ra%10-1]=-1;
					}
					if (ra%10<9)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10+1)*40,(ra/10)*40,(ra%10+2)*40,(ra/10+1)*40);
					c[ra/10][ra%10+1]=-1;
					Image2->Canvas->Rectangle((ra%10+1)*40,(ra/10-2)*40,(ra%10+2)*40,(ra/10-1)*40);
					c[ra/10-2][ra%10+1]=-1;
					}
				 }
				 if ((ra/10>2)&&(c[ra/10-1][ra%10]==-2)&&(c[ra/10-2][ra%10]==-2)&&(c[ra/10-3][ra%10]!=-2))
				  {
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10)*40,(ra/10-3)*40,(ra%10+1)*40,(ra/10-2)*40);
					c[ra/10-3][ra%10]=-1;
				 if (ra%10>0)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10-1)*40,(ra/10)*40,(ra%10)*40,(ra/10+1)*40);
					c[ra/10][ra%10-1]=-1;
					Image2->Canvas->Rectangle((ra%10-1)*40,(ra/10-2)*40,(ra%10)*40,(ra/10-1)*40);
					c[ra/10-2][ra%10-1]=-1;
					Image2->Canvas->Rectangle((ra%10-1)*40,(ra/10-3)*40,(ra%10)*40,(ra/10-2)*40);
					c[ra/10-3][ra%10-1]=-1;
					}
					if (ra%10<9)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10+1)*40,(ra/10)*40,(ra%10+2)*40,(ra/10+1)*40);
					c[ra/10][ra%10+1]=-1;
					Image2->Canvas->Rectangle((ra%10+1)*40,(ra/10-2)*40,(ra%10+2)*40,(ra/10-1)*40);
					c[ra/10-2][ra%10+1]=-1;
					Image2->Canvas->Rectangle((ra%10+1)*40,(ra/10-3)*40,(ra%10+2)*40,(ra/10-2)*40);
					c[ra/10-3][ra%10+1]=-1;
					}
				  }
				   if ((ra/10==3)&&(c[ra/10-1][ra%10]==-2)&&(c[ra/10-2][ra%10]==-2)&&(c[ra/10-3][ra%10]==-2))
				 {
					if (ra%10>0)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10-1)*40,(ra/10)*40,(ra%10)*40,(ra/10+1)*40);
					c[ra/10][ra%10-1]=-1;
					Image2->Canvas->Rectangle((ra%10-1)*40,(ra/10-2)*40,(ra%10)*40,(ra/10-1)*40);
					c[ra/10-2][ra%10-1]=-1;
					Image2->Canvas->Rectangle((ra%10-1)*40,(ra/10-3)*40,(ra%10)*40,(ra/10-2)*40);
					c[ra/10-3][ra%10-1]=-1;
					}
					if (ra%10<9)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10+1)*40,(ra/10)*40,(ra%10+2)*40,(ra/10+1)*40);
					c[ra/10][ra%10+1]=-1;
					Image2->Canvas->Rectangle((ra%10+1)*40,(ra/10-2)*40,(ra%10+2)*40,(ra/10-1)*40);
					c[ra/10-2][ra%10+1]=-1;
					Image2->Canvas->Rectangle((ra%10+1)*40,(ra/10-3)*40,(ra%10+2)*40,(ra/10-2)*40);
					c[ra/10-3][ra%10+1]=-1;
					}
				 }
				 if ((ra/10>3)&&(c[ra/10-1][ra%10]==-2)&&(c[ra/10-2][ra%10]==-2)&&(c[ra/10-3][ra%10]==-2)&&(c[ra/10-4][ra%10]!=-2))
				  {
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10)*40,(ra/10-4)*40,(ra%10+1)*40,(ra/10-3)*40);
					c[ra/10-4][ra%10]=-1;
					if (ra%10>0)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10-1)*40,(ra/10)*40,(ra%10)*40,(ra/10+1)*40);
					c[ra/10][ra%10-1]=-1;
					Image2->Canvas->Rectangle((ra%10-1)*40,(ra/10-2)*40,(ra%10)*40,(ra/10-1)*40);
					c[ra/10-2][ra%10-1]=-1;
					Image2->Canvas->Rectangle((ra%10-1)*40,(ra/10-3)*40,(ra%10)*40,(ra/10-2)*40);
					c[ra/10-3][ra%10-1]=-1;
					Image2->Canvas->Rectangle((ra%10-1)*40,(ra/10-4)*40,(ra%10)*40,(ra/10-3)*40);
					c[ra/10-4][ra%10-1]=-1;
					}
					if (ra%10<9)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10+1)*40,(ra/10)*40,(ra%10+2)*40,(ra/10+1)*40);
					c[ra/10][ra%10+1]=-1;
					Image2->Canvas->Rectangle((ra%10+1)*40,(ra/10-2)*40,(ra%10+2)*40,(ra/10-1)*40);
					c[ra/10-2][ra%10+1]=-1;
					Image2->Canvas->Rectangle((ra%10+1)*40,(ra/10-3)*40,(ra%10+2)*40,(ra/10-2)*40);
					c[ra/10-3][ra%10+1]=-1;
					Image2->Canvas->Rectangle((ra%10+1)*40,(ra/10-4)*40,(ra%10+2)*40,(ra/10-3)*40);
					c[ra/10-4][ra%10+1]=-1;
					}
				  }


				   if ((ra/10<9)&&(c[ra/10+1][ra%10]!=-2))
				  {
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10)*40,(ra/10+1)*40,(ra%10+1)*40,(ra/10+2)*40);
					c[ra/10+1][ra%10]=-1;
				  }
				  if ((ra/10==8)&&(c[ra/10+1][ra%10]==-2))
				  {
					Image2->Canvas->Brush->Color = clBlue;
					if (ra%10>0){
					Image2->Canvas->Rectangle((ra%10-1)*40,(ra/10)*40,(ra%10)*40,(ra/10+1)*40);
					c[ra/10][ra%10-1]=-1;
					}
					if (ra%10<9){
					Image2->Canvas->Rectangle((ra%10+1)*40,(ra/10)*40,(ra%10+2)*40,(ra/10+1)*40);
					c[ra/10][ra%10+1]=-1;
					}
				  }
				 if ((ra/10<8)&&(c[ra/10+1][ra%10]==-2)&&(c[ra/10+2][ra%10]!=-2))
				  {
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10)*40,(ra/10+2)*40,(ra%10+1)*40,(ra/10+3)*40);
					c[ra/10+2][ra%10]=-1;
					if (ra%10>0)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10-1)*40,(ra/10)*40,(ra%10)*40,(ra/10+1)*40);
					c[ra/10][ra%10-1]=-1;
					Image2->Canvas->Rectangle((ra%10-1)*40,(ra/10+2)*40,(ra%10)*40,(ra/10+3)*40);
					c[ra/10+2][ra%10-1]=-1;
					}
					if (ra%10<9)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10+1)*40,(ra/10)*40,(ra%10+2)*40,(ra/10+1)*40);
					c[ra/10][ra%10+1]=-1;
					Image2->Canvas->Rectangle((ra%10+1)*40,(ra/10+2)*40,(ra%10+2)*40,(ra/10+3)*40);
					c[ra/10+2][ra%10+1]=-1;
					}
				  }
				 if ((ra/10==7)&&(c[ra/10+1][ra%10]==-2)&&(c[ra/10+2][ra%10]==-2))
				 {
					if (ra%10>0)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10-1)*40,(ra/10)*40,(ra%10)*40,(ra/10+1)*40);
					c[ra/10][ra%10-1]=-1;
					Image2->Canvas->Rectangle((ra%10-1)*40,(ra/10+2)*40,(ra%10)*40,(ra/10+3)*40);
					c[ra/10+2][ra%10-1]=-1;
					}
					if (ra%10<9)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10+1)*40,(ra/10)*40,(ra%10+2)*40,(ra/10+1)*40);
					c[ra/10][ra%10+1]=-1;
					Image2->Canvas->Rectangle((ra%10+1)*40,(ra/10+2)*40,(ra%10+2)*40,(ra/10+3)*40);
					c[ra/10+2][ra%10+1]=-1;
					}
				 }
				 if ((ra/10<7)&&(c[ra/10+1][ra%10]==-2)&&(c[ra/10+2][ra%10]==-2)&&(c[ra/10+3][ra%10]!=-2))
				  {
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10)*40,(ra/10+3)*40,(ra%10+1)*40,(ra/10+4)*40);
					c[ra/10][ra%10]=-1;
					if (ra%10>0)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10-1)*40,(ra/10)*40,(ra%10)*40,(ra/10+1)*40);
					c[ra/10][ra%10-1]=-1;
					Image2->Canvas->Rectangle((ra%10-1)*40,(ra/10+2)*40,(ra%10)*40,(ra/10+3)*40);
					c[ra/10+2][ra%10-1]=-1;
					Image2->Canvas->Rectangle((ra%10-1)*40,(ra/10+3)*40,(ra%10)*40,(ra/10+4)*40);
					c[ra/10+3][ra%10-1]=-1;
					}
					if (ra%10<9)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10+1)*40,(ra/10)*40,(ra%10+2)*40,(ra/10+1)*40);
					c[ra/10][ra%10+1]=-1;
					Image2->Canvas->Rectangle((ra%10+1)*40,(ra/10+2)*40,(ra%10+2)*40,(ra/10+3)*40);
					c[ra/10+2][ra%10+1]=-1;
					Image2->Canvas->Rectangle((ra%10+1)*40,(ra/10+3)*40,(ra%10+2)*40,(ra/10+4)*40);
					c[ra/10+3][ra%10+1]=-1;
					}
				  }
				   if ((ra/10==6)&&(c[ra/10+1][ra%10]==-2)&&(c[ra/10+2][ra%10]==-2)&&(c[ra/10+3][ra%10]==-2))
				 {
					if (ra%10>0)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10-1)*40,(ra/10)*40,(ra%10)*40,(ra/10+1)*40);
					c[ra/10][ra%10-1]=-1;
					Image2->Canvas->Rectangle((ra%10-1)*40,(ra/10+2)*40,(ra%10)*40,(ra/10+3)*40);
					c[ra/10+2][ra%10-1]=-1;
					Image2->Canvas->Rectangle((ra%10-1)*40,(ra/10+3)*40,(ra%10)*40,(ra/10+4)*40);
					c[ra/10+3][ra%10-1]=-1;
					}
					if (ra%10<9)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10+1)*40,(ra/10)*40,(ra%10+2)*40,(ra/10+1)*40);
					c[ra/10][ra%10+1]=-1;
					Image2->Canvas->Rectangle((ra%10+1)*40,(ra/10+2)*40,(ra%10+2)*40,(ra/10+3)*40);
					c[ra/10+2][ra%10+1]=-1;
					Image2->Canvas->Rectangle((ra%10+1)*40,(ra/10+3)*40,(ra%10+2)*40,(ra/10+4)*40);
					c[ra/10+3][ra%10+1]=-1;
					}
				 }
				 if ((ra/10<6)&&(c[ra/10+1][ra%10]==-2)&&(c[ra/10+2][ra%10]==-2)&&(c[ra/10+3][ra%10]==-2)&&(c[ra/10+4][ra%10]!=-2))
				  {
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10)*40,(ra/10+4)*40,(ra%10+1)*40,(ra/10+5)*40);
					c[ra/10+4][ra%10]=-1;
					if (ra%10>0)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10-1)*40,(ra/10)*40,(ra%10)*40,(ra/10+1)*40);
					c[ra/10][ra%10-1]=-1;
					Image2->Canvas->Rectangle((ra%10-1)*40,(ra/10+2)*40,(ra%10)*40,(ra/10+3)*40);
					c[ra/10+2][ra%10-1]=-1;
					Image2->Canvas->Rectangle((ra%10-1)*40,(ra/10+3)*40,(ra%10)*40,(ra/10+4)*40);
					c[ra/10+3][ra%10-1]=-1;
					Image2->Canvas->Rectangle((ra%10-1)*40,(ra/10+4)*40,(ra%10)*40,(ra/10+5)*40);
					c[ra/10+4][ra%10-1]=-1;
					}
					if (ra%10<9)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10+1)*40,(ra/10)*40,(ra%10+2)*40,(ra/10+1)*40);
					c[ra/10][ra%10+1]=-1;
					Image2->Canvas->Rectangle((ra%10+1)*40,(ra/10+2)*40,(ra%10+2)*40,(ra/10+3)*40);
					c[ra/10+2][ra%10+1]=-1;
					Image2->Canvas->Rectangle((ra%10+1)*40,(ra/10+3)*40,(ra%10+2)*40,(ra/10+4)*40);
					c[ra/10+3][ra%10+1]=-1;
					Image2->Canvas->Rectangle((ra%10+1)*40,(ra/10+4)*40,(ra%10+2)*40,(ra/10+5)*40);
					c[ra/10+4][ra%10+1]=-1;
					}
				  }


				  if ((ra%10>0)&&(c[ra/10][ra%10-1]!=-2))
				  {
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10-1)*40,(ra/10)*40,(ra%10)*40,(ra/10+1)*40);
					c[ra/10][ra%10-1]=-1;
				  }
				 if ((ra%10>1)&&(c[ra/10][ra%10-1]==-2)&&(c[ra/10][ra%10-2]!=-2))
				  {
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10-2)*40,(ra/10)*40,(ra%10-1)*40,(ra/10+1)*40);
					c[ra/10][ra%10-2]=-1;
					if (ra/10>0)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10-2)*40,(ra/10-1)*40,(ra%10-1)*40,(ra/10)*40);
					c[ra/10-1][ra%10-2]=-1;
					}
					if (ra/10<9)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10-2)*40,(ra/10+1)*40,(ra%10-1)*40,(ra/10+2)*40);
					c[ra/10+1][ra%10-2]=-1;
					}
				  }
				 if ((ra%10==2)&&(c[ra/10][ra%10-1]==-2)&&(c[ra/10][ra%10-2]==-2))
				 {
					if (ra/10>0)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10-2)*40,(ra/10-1)*40,(ra%10-1)*40,(ra/10)*40);
					c[ra/10-1][ra%10-2]=-1;
					}
					if (ra/10<9)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10-2)*40,(ra/10+1)*40,(ra%10-1)*40,(ra/10+2)*40);
					c[ra/10+1][ra%10-2]=-1;
					}
				 }
				 if ((ra%10>2)&&(c[ra/10][ra%10-1]==-2)&&(c[ra/10][ra%10-2]==-2)&&(c[ra/10][ra%10-3]!=-2))
				  {
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10-3)*40,(ra/10)*40,(ra%10-2)*40,(ra/10+1)*40);
					c[ra/10][ra%10-3]=-1;
					if (ra/10>0)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10-2)*40,(ra/10-1)*40,(ra%10-1)*40,(ra/10)*40);
					c[ra/10-1][ra%10-2]=-1;
					Image2->Canvas->Rectangle((ra%10-3)*40,(ra/10-1)*40,(ra%10-2)*40,(ra/10)*40);
					c[ra/10-1][ra%10-3]=-1;
					}
					if (ra/10<9)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10-2)*40,(ra/10+1)*40,(ra%10-1)*40,(ra/10+2)*40);
					c[ra/10+1][ra%10-2]=-1;
					Image2->Canvas->Rectangle((ra%10-3)*40,(ra/10+1)*40,(ra%10-2)*40,(ra/10+2)*40);
					c[ra/10+1][ra%10-3]=-1;
					}
				  }
				   if ((ra%10==3)&&(c[ra/10][ra%10-1]==-2)&&(c[ra/10][ra%10-2]==-2)&&(c[ra/10][ra%10-3]==-2))
				 {
					if (ra/10>0)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10-2)*40,(ra/10-1)*40,(ra%10-1)*40,(ra/10)*40);
					c[ra/10-1][ra%10-2]=-1;
					Image2->Canvas->Rectangle((ra%10-3)*40,(ra/10-1)*40,(ra%10-2)*40,(ra/10)*40);
					c[ra/10-1][ra%10-3]=-1;
					}
					if (ra/10<9)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10-2)*40,(ra/10+1)*40,(ra%10-1)*40,(ra/10+2)*40);
					c[ra/10+1][ra%10-2]=-1;
					Image2->Canvas->Rectangle((ra%10-3)*40,(ra/10+1)*40,(ra%10-2)*40,(ra/10+2)*40);
					c[ra/10+1][ra%10-3]=-1;
					}
				 }
				 if ((ra%10>3)&&(c[ra/10][ra%10-1]==-2)&&(c[ra/10][ra%10-2]==-2)&&(c[ra/10][ra%10-3]==-2)&&(c[ra/10][ra%10-4]!=-2))
				  {
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10-4)*40,(ra/10)*40,(ra%10-3)*40,(ra/10+1)*40);
					c[ra/10][ra%10-4]=-1;
					if (ra/10>0)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10-2)*40,(ra/10-1)*40,(ra%10-1)*40,(ra/10)*40);
					c[ra/10-1][ra%10-2]=-1;
					Image2->Canvas->Rectangle((ra%10-3)*40,(ra/10-1)*40,(ra%10-2)*40,(ra/10)*40);
					c[ra/10-1][ra%10-3]=-1;
					Image2->Canvas->Rectangle((ra%10-4)*40,(ra/10-1)*40,(ra%10-3)*40,(ra/10)*40);
					c[ra/10-1][ra%10-4]=-1;
					}
					if (ra/10<9)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10-2)*40,(ra/10+1)*40,(ra%10-1)*40,(ra/10+2)*40);
					c[ra/10+1][ra%10-2]=-1;
					Image2->Canvas->Rectangle((ra%10-3)*40,(ra/10+1)*40,(ra%10-2)*40,(ra/10+2)*40);
					c[ra/10+1][ra%10-3]=-1;
					Image2->Canvas->Rectangle((ra%10-4)*40,(ra/10+1)*40,(ra%10-3)*40,(ra/10+2)*40);
					c[ra/10+1][ra%10-4]=-1;
					}
				  }


					if ((ra%10<9)&&(c[ra/10][ra%10+1]!=-2))
				  {
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10+1)*40,(ra/10)*40,(ra%10+2)*40,(ra/10+1)*40);
					c[ra/10][ra%10+1]=-1;
				  }
				 if ((ra%10<8)&&(c[ra/10][ra%10+1]==-2)&&(c[ra/10][ra%10+2]!=-2))
				  {
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10+2)*40,(ra/10)*40,(ra%10+3)*40,(ra/10+1)*40);
					c[ra/10][ra%10+2]=-1;
					if (ra/10>0)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10+2)*40,(ra/10-1)*40,(ra%10+3)*40,(ra/10)*40);
					c[ra/10-1][ra%10+2]=-1;
					}
					if (ra/10<9)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10+2)*40,(ra/10+1)*40,(ra%10+3)*40,(ra/10+2)*40);
					c[ra/10+1][ra%10+2]=-1;
					}
				  }
				 if ((ra%10==7)&&(c[ra/10][ra%10+1]==-2)&&(c[ra/10][ra%10+2]==-2))
				 {
					if (ra/10>0)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10+2)*40,(ra/10-1)*40,(ra%10+3)*40,(ra/10)*40);
					c[ra/10-1][ra%10+2]=-1;
					}
					if (ra/10<9)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10+2)*40,(ra/10+1)*40,(ra%10+3)*40,(ra/10+2)*40);
					c[ra/10+1][ra%10+2]=-1;
					}
				 }
				 if ((ra%10<7)&&(c[ra/10][ra%10+1]==-2)&&(c[ra/10][ra%10+2]==-2)&&(c[ra/10][ra%10+3]!=-2))
				  {
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10+3)*40,(ra/10)*40,(ra%10+4)*40,(ra/10+1)*40);
					c[ra/10][ra%10+3]=-1;
					if (ra/10>0)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10+2)*40,(ra/10-1)*40,(ra%10+3)*40,(ra/10)*40);
					c[ra/10-1][ra%10+2]=-1;
					Image2->Canvas->Rectangle((ra%10+3)*40,(ra/10-1)*40,(ra%10+4)*40,(ra/10)*40);
					c[ra/10-1][ra%10+3]=-1;
					}
					if (ra/10<9)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10+2)*40,(ra/10+1)*40,(ra%10+3)*40,(ra/10+2)*40);
					c[ra/10+1][ra%10+2]=-1;
					Image2->Canvas->Rectangle((ra%10+3)*40,(ra/10+1)*40,(ra%10+4)*40,(ra/10+2)*40);
					c[ra/10+1][ra%10+3]=-1;
					}
				  }
				   if ((ra%10==6)&&(c[ra/10][ra%10+1]==-2)&&(c[ra/10][ra%10+2]==-2)&&(c[ra/10][ra%10+3]==-2))
				 {
					if (ra/10>0)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10+2)*40,(ra/10-1)*40,(ra%10+3)*40,(ra/10)*40);
					c[ra/10-1][ra%10+2]=-1;
					Image2->Canvas->Rectangle((ra%10+3)*40,(ra/10-1)*40,(ra%10+4)*40,(ra/10)*40);
					c[ra/10-1][ra%10+3]=-1;
					}
					if (ra/10<9)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10+2)*40,(ra/10+1)*40,(ra%10+3)*40,(ra/10+2)*40);
					c[ra/10+1][ra%10+2]=-1;
					Image2->Canvas->Rectangle((ra%10+3)*40,(ra/10+1)*40,(ra%10+4)*40,(ra/10+2)*40);
					c[ra/10+1][ra%10+3]=-1;
					}
				 }
				 if ((ra%10<6)&&(c[ra/10][ra%10+1]==-2)&&(c[ra/10][ra%10+2]==-2)&&(c[ra/10][ra%10+3]==-2)&&(c[ra/10][ra%10+4]!=-2))
				  {
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10+4)*40,(ra/10)*40,(ra%10+5)*40,(ra/10+1)*40);
					c[ra/10][ra%10+4]=-1;
					if (ra/10>0)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10+2)*40,(ra/10-1)*40,(ra%10+3)*40,(ra/10)*40);
					c[ra/10-1][ra%10+2]=-1;
					Image2->Canvas->Rectangle((ra%10+3)*40,(ra/10-1)*40,(ra%10+4)*40,(ra/10)*40);
					c[ra/10-1][ra%10+3]=-1;
					Image2->Canvas->Rectangle((ra%10+4)*40,(ra/10-1)*40,(ra%10+5)*40,(ra/10)*40);
					c[ra/10-1][ra%10+4]=-1;
					}
					if (ra/10<9)
					{
					Image2->Canvas->Brush->Color = clBlue;
					Image2->Canvas->Rectangle((ra%10+2)*40,(ra/10+1)*40,(ra%10+3)*40,(ra/10+2)*40);
					c[ra/10+1][ra%10+2]=-1;
					Image2->Canvas->Rectangle((ra%10+3)*40,(ra/10+1)*40,(ra%10+4)*40,(ra/10+2)*40);
					c[ra/10+1][ra%10+3]=-1;
					Image2->Canvas->Rectangle((ra%10+4)*40,(ra/10+1)*40,(ra%10+5)*40,(ra/10+2)*40);
					c[ra/10+1][ra%10+4]=-1;
					}
				  }
				}
     don=1;
  }
 }
 }
}

void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
if (ywin==20)
{
Label5->Caption="Вы победили!";
Timer2->Enabled=False;
end=1;
}
if (cwin==20)
{
Label5->Caption="Вы проиграли.";
for (int i=0; i < 100; i++)
 if (a[i/10][i%10]==0)
  {
  Image1->Canvas->Brush->Color = clYellow;
  Image1->Canvas->Ellipse((i%10)*40,(i/10)*40,(i%10+1)*40, (i/10+1)*40);
  }
Timer2->Enabled=False;
end=1;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
 Form2->Show();
 Form2->Caption="Инструкция";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N2Click(TObject *Sender)
{
  if (gotovo==1) {
	Image1->Visible=True;

 Label1->Visible=True;
  Label4->Visible=True;
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
		a[i][j]=2;

   srand(time(0));

   while (done==0)
   {
	int b1=rand()%100;
	if (a[b1/10][b1%10]==2)
	{
	 int nap=rand()%4;
	 if ((nap==0)&&(b1%10>=3))
	 {
		a[b1/10][b1%10]=0;
		a[b1/10][b1%10-1]=0;
		a[b1/10][b1%10-2]=0;
		a[b1/10][b1%10-3]=0;
	   for (int i=b1/10-1;i<b1/10+2;i++)
		for (int j=b1%10-4;j<b1%10+2;j++)
		 if (a[i][j]>0)
		  a[i][j]=1;
		done=1;

	 }
 if ((nap==1)&&(b1/10>=3))
	 {
		a[b1/10][b1%10]=0;
		a[b1/10-1][b1%10]=0;
        a[b1/10-2][b1%10]=0;
		a[b1/10-3][b1%10]=0;
        for (int i=b1/10-4;i<b1/10+2;i++)
		for (int j=b1%10-1;j<b1%10+2;j++)
         if ((a[i][j]>0)&&(i>=0)&&(j>=0)&&(i<=9)&&(j<=9))
		  a[i][j]=1;
     done=1;
	 }
       if ((nap==2)&&(b1%10<=6))
	 {
        a[b1/10][b1%10]=0;
		a[b1/10][b1%10+1]=0;
        a[b1/10][b1%10+2]=0;
		a[b1/10][b1%10+3]=0;
        for (int i=b1/10-1;i<b1/10+2;i++)
		for (int j=b1%10-1;j<b1%10+5;j++)
         if ((a[i][j]>0)&&(i>=0)&&(j>=0)&&(i<=9)&&(j<=9))
		  a[i][j]=1;
     done=1;
	 }
        if ((nap==3)&&(b1/10<=6))
	 {
        a[b1/10][b1%10]=0;
		a[b1/10+1][b1%10]=0;
        a[b1/10+2][b1%10]=0;
		a[b1/10+3][b1%10]=0;
        for (int i=b1/10-1;i<b1/10+5;i++)
		for (int j=b1%10-1;j<b1%10+2;j++)
         if (((a[i][j]>0)&&(i>=0))&&(((j>=0)&&(i<=9))&&(j<=9)))
		  a[i][j]=1;
     done=1;
	 }
    }
   }

   while (done2<=1)
   {
	int b2=rand()%100;
    if (a[b2/10][b2%10]==2)
	{
     int nap=rand()%4;
	 if ((nap==0)&&(b2%10>=2)&&(a[b2/10][b2%10-2]==2))
     {
		a[b2/10][b2%10]=0;
        a[b2/10][b2%10-1]=0;
		a[b2/10][b2%10-2]=0;

	   for (int i=b2/10-1;i<b2/10+2;i++)
        for (int j=b2%10-3;j<b2%10+2;j++)
		 if (a[i][j]>0)
          a[i][j]=1;
		done2++;

	 }
 if ((nap==1)&&(b2/10>=2)&&(a[b2/10-2][b2%10]==2))
	 {
        a[b2/10][b2%10]=0;
		a[b2/10-1][b2%10]=0;
        a[b2/10-2][b2%10]=0;

        for (int i=b2/10-3;i<b2/10+2;i++)
		for (int j=b2%10-1;j<b2%10+2;j++)
         if (a[i][j]>0)
		  a[i][j]=1;
     done2++;
	 }
       if ((nap==2)&&(b2%10<=7)&&(a[b2/10][b2%10+2]==2))
	 {
        a[b2/10][b2%10]=0;
		a[b2/10][b2%10+1]=0;
        a[b2/10][b2%10+2]=0;

       for (int i=b2/10-1;i<b2/10+2;i++)
		for (int j=b2%10-1;j<b2%10+4;j++)
         if (a[i][j]>0)
		  a[i][j]=1;
        done2++;

     }
		if ((nap==3)&&(b2/10<=7)&&(a[b2/10+2][b2%10]==2))
     {
		a[b2/10][b2%10]=0;
        a[b2/10+1][b2%10]=0;
		a[b2/10+2][b2%10]=0;

		for (int i=b2/10-1;i<b2/10+4;i++)
        for (int j=b2%10-1;j<b2%10+2;j++)
		 if (a[i][j]>0)
          a[i][j]=1;
	 done2++;
     }
	}
   }

   while (done3<=2)
   {
    int b3=rand()%100;
	if (a[b3/10][b3%10]==2)
    {
     int nap=rand()%4;
	 if ((nap==0)&&(b3%10>=1)&&(a[b3/10][b3%10-1]==2))
     {
        a[b3/10][b3%10]=0;
		a[b3/10][b3%10-1]=0;
       for (int i=b3/10-1;i<b3/10+2;i++)
        for (int j=b3%10-2;j<b3%10+2;j++)
		 if (a[i][j]>0)
          a[i][j]=1;
		done3++;
     }
	 if ((nap==1)&&(b3/10>=1)&&(a[b3/10-1][b3%10]==2))
     {
		a[b3/10][b3%10]=0;
        a[b3/10-1][b3%10]=0;
	   for (int i=b3/10-2;i<b3/10+2;i++)
        for (int j=b3%10-1;j<b3%10+2;j++)
		 if (a[i][j]>0)
          a[i][j]=1;
		done3++;
     }
		if ((nap==2)&&(b3%10<=8)&&(a[b3/10][b3%10+1]==2))
     {
		a[b3/10][b3%10]=0;
        a[b3/10][b3%10+1]=0;
	   for (int i=b3/10-1;i<b3/10+2;i++)
        for (int j=b3%10-1;j<b3%10+3;j++)
		 if (a[i][j]>0)
          a[i][j]=1;
		done3++;
     }
	   if ((nap==3)&&(b3/10<=8)&&(a[b3/10+1][b3%10]==2))
     {
		a[b3/10][b3%10]=0;
        a[b3/10+1][b3%10]=0;
	   for (int i=b3/10-1;i<b3/10+3;i++)
        for (int j=b3%10-1;j<b3%10+2;j++)
		 if (a[i][j]>0)
          a[i][j]=1;
		done3++;
     }
	}
   }

   while (done4<=3)
   {
    int b4=rand()%100;
	if (a[b4/10][b4%10]==2)
    {
		a[b4/10][b4%10]=0;
       for (int i=b4/10-1;i<b4/10+2;i++)
		for (int j=b4%10-1;j<b4%10+2;j++)
         if (a[i][j]>0)
		  a[i][j]=1;
        done4++;
	 }
   }
	for(int i=0;i<10;i++)
	 for(int j=0;j<10;j++)
	  if (a[i][j]==2)
		  a[i][j]=1;
	 Label2->Visible=False;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N1Click(TObject *Sender)
{
  done=0;
   done2=0;
	done3=0;
	done4=0;
	 end=0;
	  ywin=0;
	   cwin=0;
	   level=0;
		 si=0;
		  situ=0;
		  ka=0;
		  start=0;
		   ch1=0;
		   ch2=0;
		   ch3=0;
			per=0;
			 got=0;
			  hod=0;
			  bit=0;
			   ra=0;
				gotovo=0;
  for (int i=0; i < 4; i++) {
	ad1[i]=0;
	if (i<2)
	{
	ad2[i]=0;
	ad3[i]=0;
	}
}
  for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
		m[i][j]=1;
		LabeledEdit1->Text="1";
		LabeledEdit2->Text="2";
		LabeledEdit3->Text="3";
		LabeledEdit4->Text="4";
Image1->Canvas->Brush->Color = clGray;
	Image1->Canvas->Rectangle(0,0,400,400);
	Image3->Canvas->Brush->Color = clSkyBlue;
	Image3->Height=40;
	Image3->Width=160;
	Image4->Height=40;
	Image4->Width=120;
	Image5->Height=40;
	Image5->Width=80;
	Image3->Canvas->Rectangle(0,0,160,160);
		Image4->Canvas->Brush->Color = clSkyBlue;
	Image4->Canvas->Rectangle(0,0,120,120);
		Image5->Canvas->Brush->Color = clSkyBlue;
	Image5->Canvas->Rectangle(0,0,80,80);
  for (int i=0; i < 9; i++) {
  Image1->Canvas->MoveTo(0,(i+1)*40);
	Image1->Canvas->LineTo(400,(i+1)*40);
	Image1->Canvas->MoveTo((i+1)*40,0);
	Image1->Canvas->LineTo((i+1)*40,400);
}
Image2->Canvas->Brush->Color = clGray;
	Image2->Canvas->Rectangle(0,0,400,400);
  for (int i=0; i < 9; i++) {
  Image2->Canvas->MoveTo(0,(i+1)*40);
	Image2->Canvas->LineTo(400,(i+1)*40);
	Image2->Canvas->MoveTo((i+1)*40,0);
	Image2->Canvas->LineTo((i+1)*40,400);
}
 ris->Width=160;
 ris->Height=320;
 ris -> LoadFromFile("karabli.bmp");
 krest->Width=40;
 krest->Height=40;
 krest -> LoadFromFile("krest.bmp");
 krest->Transparent=True;
 Pr4h=Bounds(0,0,160,40);
 Pr3h=Bounds(0,40,120,40);
 Pr2h=Bounds(0,80,80,40);
 Pr4v=Bounds(0,160,40,160);
 Pr3v=Bounds(40,160,40,120);
 Pr2v=Bounds(80,160,40,80);
 Pr1=Bounds(0,120,40,40);
 P04h=Bounds(0,0,160,40);
 P03h=Bounds(0,0,120,40);
 P02h=Bounds(0,0,80,40);
 P04v=Bounds(0,0,40,160);
 P03v=Bounds(0,0,40,120);
 P02v=Bounds(0,0,40,80);
 P01=Bounds(0,0,40,40);
 k4h->Width=160;
 k4h->Height=40;
 k3h->Width=120;
 k3h->Height=40;
 k2h->Width=80;
 k2h->Height=40;
 k4v->Width=40;
 k4v->Height=160;
 k3v->Width=40;
 k3v->Height=120;
 k2v->Width=40;
 k2v->Height=80;
 k1->Width=40;
 k1->Height=40;
 k4h->Canvas->CopyRect(P04h,ris->Canvas,Pr4h);
 k4v->Canvas->CopyRect(P04v,ris->Canvas,Pr4v);
 k3h->Canvas->CopyRect(P03h,ris->Canvas,Pr3h);
 k3v->Canvas->CopyRect(P03v,ris->Canvas,Pr3v);
 k2h->Canvas->CopyRect(P02h,ris->Canvas,Pr2h);
 k2v->Canvas->CopyRect(P02v,ris->Canvas,Pr2v);
 k1->Canvas->CopyRect(P01,ris->Canvas,Pr1);
 Image3->Canvas->Draw(0,0,k4h);
 Image4->Canvas->Draw(0,0,k3h);
 Image5->Canvas->Draw(0,0,k2h);
 Image6->Canvas->Draw(0,0,k1);
 Label2->Caption="Расставьте Ваши корабли";
 LabeledEdit1->Visible=True;
 LabeledEdit2->Visible=True;
 LabeledEdit3->Visible=True;
 LabeledEdit4->Visible=True;
 BitBtn1->Visible=True;
 BitBtn2->Visible=True;
 BitBtn3->Visible=True;
 Image3->Visible=True;
  Image4->Visible=True;
   Image5->Visible=True;
	Image6->Visible=True;
	Label2->Visible=True;
	Label4->Visible=False;
	Image1->Visible=False;
	Button2->Visible=True;
	Button2->Enabled=False;
	Label5->Visible=False;
	Label1->Visible=False;
	Timer1->Enabled=False;
	Timer2->Enabled=True;
}
//---------------------------------------------------------------------------

