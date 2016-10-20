#include"Suken.h"
#include"MyScene.h"

CScene 
	TITLE,
	SELECT,
	MAIN,
    MAIN1,
	MAIN2,
	CLEAR;

int g_title;

int g_hake;

int g_jiki;

int g_clear;

int g_goal;

int g_person;

int g_mushoku;

int g_falsegreenbox;

int g_select;

int g_a;

int g_haikei;

int g_stage[4];
int masucolor[150][40];
int masucolor2[200][40];
int masucolor3[54][86];

void AwakeScene()
{

	Game.AddChild(&TITLE);

	TITLE.input.AddEventListener(Event.EVERY_FRAME,DrawGameTitle);
	MAIN.input.AddEventListener(Event.EVERY_FRAME,DrawGameMain);
	MAIN1.input.AddEventListener(Event.EVERY_FRAME,DrawGameMain1);
	MAIN2.input.AddEventListener(Event.EVERY_FRAME,DrawGameMain2);
	//STAGE2.input.AddEventListener(Event.EVERY_FRAME,DrawGameStage2);
	SELECT.input.AddEventListener(Event.EVERY_FRAME,DrawGameSelect);
	CLEAR.input.AddEventListener(Event.EVERY_FRAME,DrawGameClear);

	g_title = LoadGraph("hiraokapic/Title.png",true);

	g_hake = LoadGraph("hiraokapic/Mesa.png",true);

	g_jiki = LoadGraph("hiraokapic/jiki.png",true);

	g_clear = LoadGraph("hiraokapic/Clear.png",true);

	g_goal = LoadGraph("hiraokapic/goal.png",true);

	g_person = LoadGraph("hiraokapic/person.png",true);

	g_mushoku = LoadGraph("hiraokapic/mushoku.png",true);

	g_falsegreenbox = LoadGraph("hiraokapic/falsegreenbox.png",true);

	g_select = LoadGraph("hiraokapic/select2.png",true);

	g_a = LoadGraph("hiraokapic/a.png",true);

	g_haikei = LoadGraph("hiraokapic/ushiro.png",true);

	g_stage[1] =LoadSoftImage("hiraokapic/Sta1.png"); 
	int r,g,b;
	for(int i=0;i<150;i++){
		for(int j=0;j<40;j++){
			GetPixelSoftImage(g_stage[1],i,j,&r,&g,&b,0);
			masucolor[i][j] = GetColor(r,g,b);
		}
	}
	 g_stage[2] =LoadSoftImage("hiraokapic/neko.png"); 
	int r2,g2,b2;
	for(int a=0;a<200;a++){
		for(int b=0;b<40;b++){
			GetPixelSoftImage(g_stage[2],a,b,&r2,&g2,&b2,0);
			masucolor2[a][b] = GetColor(r2,g2,b2);
		}}

 g_stage[3] =LoadSoftImage("hiraokapic/alpaca.png"); 
	int r3,g3,b3;
	for(int i2=0;i2<54;i2++){
		for(int j2=0;j2<86;j2++){
			GetPixelSoftImage(g_stage[3],i2,j2,&r3,&g3,&b3,0);
			masucolor3[i2][j2] = GetColor(r3,g3,b3);
		}
	}	


}
   
 




void DrawGameTitle(){
	DrawGraph(0,0,g_title,true);
	
	if(CheckHitKey(KEY_INPUT_RETURN)){
		GoGameSelect();
	}
}
void DrawGameClear(){
DrawGraph(0,0,g_clear,true);
if(CheckHitKey(KEY_INPUT_RETURN)){
		GoGameSelect();
	}
}








int goal_x=2300;
int goal_y=0;





int ao_x[5] = {0,50,0,50,50};
int ao_y[5] = {0,200,400,600,800};
const int ao_w[5] = {10000,9950,9950,9950,9950};
const int ao_h[5] = {80,80,80,80,80};

const int jiki_X = 30;
const int jiki_Y = 60;

int x=2050;
int y=150;



int vx=0;
int vy=0;
int z=1;


int box_a1=0,box_b1=530;

int box_a2=100,box_b2=400;

int scr_x = 0;
int scr_y = 0;

bool scr_f=false;
bool flag=false;
bool jump_f=false;
bool scr_fx3=false;
bool scr_fy3=false;
bool flag3=false;
bool jump_f3=false;
bool scr_f2=false;
bool flag2=false;
bool jump_f2=false;

int goal_x2=1590;
int goal_y2=0;
const int jiki_X2 = 30;
const int jiki_Y2 = 60;
int scr_x2 = 0;
int scr_y2 = 0;
int x2=1800;
int y2=30;
int vx2=0;
int vy2=0;
int z2=1;

int goal_x3=1590;
int goal_y3=0;
const int jiki_X3= 30;
const int jiki_Y3 = 60;
int scr_x3 = 0;
int scr_y3 = 0;
int x3=530;
int y3=220;
int vx3=0;
int vy3=0;
int z3=1;


void Collision(int _box_x,int _box_y,int _box_w,int _box_h){

		if(x+vx+jiki_X>_box_x && x+vx<_box_x+_box_w && y>_box_y-60 && y<_box_y+_box_h && vx>=0 ){
		
		x=_box_x-jiki_X;
		vx=0;
		}

		if(x+vx+jiki_X>_box_x+_box_w &&x+vx<_box_w+_box_x  && y>_box_y-60 && y<_box_y+_box_h  && vx<=0){
			x = _box_x + _box_w;
			vx=0;
			}

	if(x+vx>_box_x-30 && x+vx<_box_x+_box_w && y+vy>=_box_y-60 && y<_box_y+_box_h && vy>0){
			y = _box_y - jiki_Y;
			vy=0;
			jump_f=true;
		}

	if(x+vx>_box_x-30 && x+vx<_box_x+_box_w && y+vy<=_box_y+_box_h && y>_box_y-60 && vy<0){
			y = _box_y + _box_h;
			vy =0;
		}
	
	
	
};

void Collision2(int _box_x,int _box_y,int _box_w,int _box_h){

		if(x2+vx2+jiki_X2>_box_x && x2+vx2<_box_x+_box_w && y2>_box_y-60 && y2<_box_y+_box_h && vx2>=0 ){
		
		x2=_box_x-jiki_X2;
		vx2=0;
		}

		if(x2+vx2+jiki_X2>_box_x+_box_w &&x2+vx2<_box_w+_box_x  && y2>_box_y-60 && y2<_box_y+_box_h  && vx2<=0){
			x2 = _box_x + _box_w;
			vx2=0;
			}

	if(x2+vx2>_box_x-30 && x2+vx2<_box_x+_box_w && y2+vy2>=_box_y-60 && y2<_box_y+_box_h && vy2>0){
			y2 = _box_y - jiki_Y;
			vy2=0;
			jump_f2=true;
		}

	if(x2+vx2>_box_x-30 && x2+vx2<_box_x+_box_w && y2+vy2<=_box_y+_box_h && y2>_box_y-60 && vy2<0){
			y2 = _box_y + _box_h;
			vy2 =0;
		}
	
	
	
};
void Collision3(int _box_x,int _box_y,int _box_w,int _box_h){

		if(x3+vx3+jiki_X3>_box_x && x3+vx3<_box_x+_box_w && y3>_box_y-60 && y3<_box_y+_box_h && vx3>=0 ){
		
		x3=_box_x-jiki_X;
		vx3=0;
		}

		if(x3+vx3+jiki_X3>_box_x+_box_w &&x3+vx3<_box_w+_box_x  && y3>_box_y-60 && y3<_box_y+_box_h  && vx3<=0){
			x3 = _box_x + _box_w;
			vx3=0;
			}

	if(x3+vx3>_box_x-30 && x3+vx3<_box_x+_box_w && y3+vy3>=_box_y-60 && y3<_box_y+_box_h && vy3>0){
			y3 = _box_y - jiki_Y3;
			vy3=0;
			jump_f3=true;
		}

	if(x3+vx3>_box_x-30 && x3+vx3<_box_x+_box_w && y3+vy3<=_box_y+_box_h && y3>_box_y-60 && vy3<0){
			y3 = _box_y + _box_h;
			vy3 =0;
		}
	
	
	
};

void DrawGameSelect(){
	 DrawGraph(0,0,g_select,true);

	if(CheckHitKey(KEY_INPUT_1)){
		GoGameMain();
	}

	if(CheckHitKey(KEY_INPUT_2)){
		GoGameMain1();
	}
if(CheckHitKey(KEY_INPUT_3)){
		GoGameMain2();
	}
};




//STAGE1
void DrawGameMain(){
	flag = false;
	

	


	if(flag == false){
		if(CheckHitKey(KEY_INPUT_RIGHT)){
			vx += 5;
		}
		if(CheckHitKey(KEY_INPUT_LEFT)){
			vx -= 5;
		}
		if( jump_f == true){
			if(CheckHitKey(KEY_INPUT_UP)){
				vy -=14;
				jump_f = false;
			}
		}
	}

	jump_f = false;

	if(x+vx < 0 ){
		vx=0;
		x=0;
	}
	
	
	if(y+vy > 600){
		vy=0;
		x=2050;
		vx=0;
		y=150;
		scr_x=0;
	}
	
	///
	


	
	for(int i=0;i<150;i++){
		for(int j=0;j<40;j++){
			if(masucolor[i][j]==GREEN){
			Collision(i*20,j*15,20,15);
			DrawBox(i*20-scr_x,j*15,i*20+20-scr_x,j*15+15,GREEN,true);
			}
				if(masucolor[i][j]==RED){
			Collision(i*20,j*15,20,15);
			DrawBox(i*20-scr_x,j*15,i*20+20-scr_x,j*15+15,RED,true);
			}
		}
	}

	x += vx;
	y += vy;
	vx=0;

	if(jump_f==false){
		vy+=z;
	}else{
		if(vy!=0){
			vy=0;
		}
	}
		
		if(x>350&&scr_f==false){
		scr_x=x-350;
		scr_f=true;
	}
	if(x<=350){
	scr_f=false;
	}
	if(scr_f==true){
		scr_x=x-350;
		scr_f=true;
	}
	
	
	if(x >= goal_x -30 && y >= goal_y -60  && x <= goal_x +30 && y <= goal_y + 60){
		x=2050;
		y=150;
		scr_x=0;
		flag = true;
	}
	if(flag ==true){

		GoGameClear();

		if(CheckHitKey(KEY_INPUT_RETURN)){
		GoGameSelect();
		}
		flag = false;
	}
	
	
	DrawGraph(goal_x-scr_x,goal_y,g_goal,true);
	DrawGraph(x-scr_x,y,g_person,true);	
	DrawBox(x-scr_x,y,x+jiki_X-scr_x,y+jiki_Y,WHITE,false);
	DrawFormatString(700,0,RED,"x:%d",x);
	DrawFormatString(700,20,RED,"y:%d",y);
	if(CheckHitKey(KEY_INPUT_BACK)){
		x=385;
		y=540;

		vx=0;
		vy=0;
		GoGameSelect();
	}

};
///sta2
void DrawGameMain1(){
	DrawGraph(0,0,g_haikei,true);
	flag2 = false;
	

	


	if(flag2 == false){
		if(CheckHitKey(KEY_INPUT_RIGHT)){
			vx2 += 5;
		}
		if(CheckHitKey(KEY_INPUT_LEFT)){
			vx2 -= 5;
		}
		if( jump_f2 == true){
			if(CheckHitKey(KEY_INPUT_UP)){
				vy2 =-14;
				jump_f2 = false;
			}
		}
	}

	jump_f2 = false;

	if(x2+vx2 < 0 ){
		vx2=0;
		x2=0;
	}
	
	
	if(y2+vy2 > 600){
		vy2=0;
		vx2=0;
		x2=2100;
		y2=400;
		scr_x2=0;
	}
	
	///
	


	
	for(int a=0;a<200;a++){
		for(int b=0;b<40;b++){
			if(masucolor2[a][b]==BLUE){
			Collision2(a*20,b*15,20,15);
			DrawBox(a*20-scr_x2,b*15,a*20+20-scr_x2,b*15+15,BLUE,true);
			}
			
		}
	}

	x2 += vx2;
	y2 += vy2;
	vx2=0;

	if(jump_f2==false){
		vy2+=z2;
	}else{
		if(vy2!=0){
			vy2=0;
		}
	}
		
		if(x2>350&&scr_f2==false){
		scr_x2=x2-350;
		scr_f2=true;
	}
	if(x2<=350){
	scr_f2=false;
	}
	if(scr_f2==true){
		scr_x2=x2-350;
		scr_f2=true;
	}
	
	
	if(x2 >= goal_x2 -30 && y2 >= goal_y2 -60  && x2 <= goal_x2+30 && y2 <= goal_y2 + 60){
		x2=10000;
		y2=150;
		scr_x2=0;
		flag2 = true;
	}
	if(flag2 ==true){

		GoGameClear();

		if(CheckHitKey(KEY_INPUT_RETURN)){
		GoGameSelect();
		}
		flag2 = false;
	}
	
	
	DrawGraph(goal_x2-scr_x2,goal_y2,g_goal,true);
	DrawGraph(x2-scr_x2,y2,g_person,true);	
	DrawBox(x2-scr_x2,y2,x2+jiki_X2-scr_x2,y2+jiki_Y2,WHITE,false);
	DrawFormatString(700,0,RED,"x:%d",x2);
	DrawFormatString(700,20,RED,"y:%d",y2);
	if(CheckHitKey(KEY_INPUT_BACK)){
		x2=385;
		y2=540;

		vx2=0;
		vy2=0;
		GoGameSelect();
	}

};
//sta3
void DrawGameMain2(){
	DrawGraph(0,0,g_haikei,true);

	flag3 = false;

	if(flag3 == false){
		if(CheckHitKey(KEY_INPUT_RIGHT)){
			vx3 += 5;
		}
		if(CheckHitKey(KEY_INPUT_LEFT)){
			vx3-= 5;
		}
		if( jump_f3 == true){
			if(CheckHitKey(KEY_INPUT_UP)){
				vy3 -=14;
				jump_f3 = false;
			}
		}
	}

	jump_f3 = false;

	if(x3+vx3 < 0 ){
		vx3=0;
		x3=0;
	}
	
	
	if(y3+vy3 > 1300){
		vy3=0;
		x3=200;
		vx3=0;
		y3=150;
		scr_x3=0;
		scr_y3=0;
	}
	
	
	//if(690<x3+vx3<740 && y=1005){}
	


	
	for(int i2=0;i2<54;i2++){
		for(int j2=0;j2<86;j2++){
			if(masucolor3[i2][j2]==BLACK){
			Collision3(i2*20,j2*15,20,15);
			DrawBox(i2*20-scr_x3,j2*15-scr_y3,i2*20+20-scr_x3,j2*15+15-scr_y3,BLACK,true);
			}
			if(masucolor3[i2][j2]==RED){
			Collision3(i2*20,j2*15,20,15);
			DrawBox(i2*20-scr_x3,j2*15-scr_y3,i2*20+20-scr_x3,j2*15+15-scr_y3,RED,true);
			}
	}
	}

	x3 += vx3;
	y3 += vy3;
	vx3=0;
	

	if(jump_f3==false){
		vy3+=z3;
	}else{
		if(vy3!=0){
			vy3=0;
		}
	}
		
	if(x3>350&&scr_fx3==false){
		scr_x3=x3-350;
		scr_fx3=true;
	}
	if(x3<=350){
	scr_fx3=false;
	}
	if(scr_fx3==true){
		scr_x3=x3-350;
		scr_fx3=true;
	} 

		
	if(y3>300&&scr_fy3==false){
		scr_y3=y3-300;
		scr_fy3=true;
	}
	if(y3<=300){
	scr_fy3=false;
	}
	if(scr_fy3==true){
	scr_y3=y3-300;
	scr_fy3=true;
	}
	
	
	if(x3 >= goal_x3 -30 && y3 >= goal_y3 -60  && x3 <= goal_x3 +30 && y3 <= goal_y3 + 60){
		x3=2050;
		y3=150;
		scr_x3=0;
		scr_y3=0;
		flag3= true;
	}
	if(flag3 ==true){

		GoGameClear();
	}
		if(CheckHitKey(KEY_INPUT_RETURN)){
		GoGameSelect();
		}
		flag3 = false;
	
	
	
	DrawGraph(goal_x3-scr_x3,goal_y3-scr_y3,g_goal,true);
	DrawGraph(x3-scr_x3,y3-scr_y3,g_person,true);	
	DrawBox(x3-scr_x3,y3-scr_y3,x3+jiki_X3-scr_x3,y3+jiki_Y3-scr_y3,WHITE,false);
	DrawFormatString(700,0,RED,"x:%d",x3);
	DrawFormatString(700,20,RED,"y:%d",y3);
	if(CheckHitKey(KEY_INPUT_BACK)){
		x3=540;
		y3=220;

		vx3=0;
		vy3=0;
		GoGameSelect();
	}

};

void GoGameTitle(){
	
	Game.RemoveChild();
	Game.AddChild(&TITLE);
}

void GoGameMain(){
	
	Game.RemoveChild();
	Game.AddChild(&MAIN);
}

void GoGameSelect(){
	
	Game.RemoveChild();
	Game.AddChild(&SELECT);
}

void GoGameMain1(){
	
	Game.RemoveChild();
	Game.AddChild(&MAIN1);
}
void GoGameMain2(){
	
	Game.RemoveChild();
	Game.AddChild(&MAIN2);
}


void GoGameClear(){
	
	Game.RemoveChild();
	Game.AddChild(&CLEAR);
}