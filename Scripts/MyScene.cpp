#include"Suken.h"
#include"MyScene.h"

CScene 
	TITLE,
	SELECT,
	MAIN,
    MAIN1;

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

int g_stage[4];
int masucolor[150][40];
int masucolor2[144][40];

void AwakeScene()
{

	Game.AddChild(&TITLE);

	TITLE.input.AddEventListener(Event.EVERY_FRAME,DrawGameTitle);
	MAIN.input.AddEventListener(Event.EVERY_FRAME,DrawGameMain);
	MAIN1.input.AddEventListener(Event.EVERY_FRAME,DrawGameMain1);
	//STAGE2.input.AddEventListener(Event.EVERY_FRAME,DrawGameStage2);
	SELECT.input.AddEventListener(Event.EVERY_FRAME,DrawGameSelect);

	g_title = LoadGraph("pic/Title.png",true);

	g_hake = LoadGraph("pic/Mesa.png",true);

	g_jiki = LoadGraph("pic/jiki.png",true);

	g_clear = LoadGraph("pic/game_clear.png",true);

	g_goal = LoadGraph("pic/goal.png",true);

	g_person = LoadGraph("pic/person.png",true);

	g_mushoku = LoadGraph("pic/mushoku.png",true);

	g_falsegreenbox = LoadGraph("pic/falsegreenbox.png",true);

	g_select = LoadGraph("pic/select2.png",true);

	g_a = LoadGraph("pic/a.png",true);

	g_stage[1] =LoadSoftImage("pic/Sta1.png"); 
	int r,g,b;
	for(int i=0;i<150;i++){
		for(int j=0;j<40;j++){
			GetPixelSoftImage(g_stage[1],i,j,&r,&g,&b,0);
			masucolor[i][j] = GetColor(r,g,b);
		}
	}
	 g_stage[2] =LoadSoftImage("pic/sta2.png"); 
	int r2,g2,b2;
	for(int i=0;i<144;i++){
		for(int j=0;j<40;j++){
			GetPixelSoftImage(g_stage[1],i,j,&r2,&g2,&b2,0);
			masucolor2[i][j] = GetColor(r2,g2,b2);
		}
	}

}
   
 




void DrawGameTitle(){
	DrawGraph(0,0,g_title,true);
	
	if(CheckHitKey(KEY_INPUT_RETURN)){
		GoGameSelect();
	}
}







//STAGE1
//int midori_x[16] = {0,120,200,320,380,490,570,730,810,1010,1100,1220,1360,1500,1610,1760}; 
//int midori_y[16] = {540,540,540,540,540,540,540,540,540,540,430,390,300,280,330,200};
//const int midori_X[16] = {60,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20};
//const int midori_Y[16] = {15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15};
//
//int aka_x[2] = {630,910};
//int	aka_y[2] = {510,500};
//const int aka_X[2] = {20,20};
//const int aka_Y[2] = {15,15};
//
//int falsegreenbox_x[5] = {280,350,410,630,910};
//int	falsegreenbox_y[5] = {540,540,540,510,500};
//
//int a_x[5] = {100,200,300,400,500};
//int	a_y[5] = {300,300,300,300,300};
//#define a_w 20
//#define a_h 15
//
//int mushoku_x[2] = {260,1210};
//int	mushoku_y[2] = {390,300};
//const int mushoku_X[2] = {20,30};
//
//const int mushoku_Y[2] = {15,15};

int goal_x=1900;
int goal_y=0;


//STAGE2
int goal_x2=10000;
int goal_y2=900;

int ao_x[5] = {0,50,0,50,50};
int ao_y[5] = {0,200,400,600,800};
const int ao_w[5] = {10000,9950,9950,9950,9950};
const int ao_h[5] = {80,80,80,80,80};

const int jiki_X = 30;

const int jiki_Y = 60;

int x=100;
int y=240;

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

void Collision(int _box_x,int _box_y,int _box_w,int _box_h){
	/*if(x+vx>=_box_x-jiki_X && x+vx<_box_x+_box_w && y>_box_y-60 && y<_box_y+_box_h && vx>0 &&vy==0){
		
		x=_box_x-jiki_X;
			vx=0;
			vy=0;
		}
	if(x+vx>=_box_x-jiki_X && x+vx<_box_x+_box_w && y>_box_y-60 && y<_box_y+_box_h && vx>0 &&vy<0){
		x=_box_x-jiki_X;
		y=_box_y+_box_h;
			vx=0;
			vy=0;
		}
	if(x+vx>=_box_x-jiki_X && x+vx<_box_x+_box_w && y>_box_y-60 && y<_box_y+_box_h && vx>0 &&vy>0){
		x=_box_x-jiki_X;
		y=_box_y-jiki_X;
			vx=0;
			vy=0;
			jump_f=true;
		}

	if(x+vx>_box_x-30 && x+vx<=_box_x+_box_w && y>_box_y-60 && y<_box_y+_box_h && vx<=0 && vy==0){
			x = _box_x + _box_w;
			vx = 0;
		}
	if(x+vx>_box_x-30 && x+vx<=_box_x+_box_w && y>_box_y-60 && y<_box_y+_box_h && vx<=0 && vy<0){
			x = _box_x + _box_w;
			y = _box_y + _box_h;
			vx = 0;
			vy = 0;
		}*/

	//if(x+vx>_box_x-30 && x+vx<=_box_x+_box_w && y>_box_y-60 && y<_box_y+_box_h && vx<=0 && vy>0){
	//		x = _box_x + _box_w;
	//		y = _box_y-jiki_Y;
	//		vx = 0;
	//		vy = 0;
	//		jump_f=true;
	//	}
	//	if(x+vx>_box_x-30 && x+vx<=_box_x+_box_w && y>_box_y-60 && y<_box_y+_box_h && vx==0 && vy<0){
	//		
	//		y = _box_y+_box_h;
	//		
	//		vy = 0;
	//	}
	//		if(x+vx>_box_x-30 && x+vx<=_box_x+_box_w && y>_box_y-60 && y<_box_y+_box_h && vx==0 && vy>0){
	//		
	//			
	//		y = _box_y-jiki_Y;
	//		
	//		vy = 0;
	//		jump_f=true;
	//	}
		/*if( x<_box_x+_box_w && x+jiki_X>_box_x+_box_w&& y<_box_y+_box_h && y+jiki_Y>_box_y+_box_h && vy<0){
		    x =	_box_x+_box_w;
	     	y = _box_y + _box_h;
			vx=0;
			vy =0;
		}*/
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
	
	
	/*	if(x>_box_x-30 && x+vx<_box_x+_box_w && y+vy>=_box_y-60 && y<_box_y+_box_h ){
			y = _box_y - jiki_Y;
			vy=0;
			jump_f=true;
		}

		if(x>_box_x-30 && x+vx<_box_x+_box_w && y+vy<=_box_y+_box_h && y>_box_y-60 ){
			y = _box_y + _box_h;
			vy =0;
		}*/
		//if(x+jiki_X>=_box_x &&  y+jiki_Y>_box_y )
		//	x=_box_x-jiki_X;
		////	y=_box_y-jiki_Y;
		//if(x+jiki_X>=_box_x && y<_box_y+_box_h){
		//	x=_box_x-jiki_X;
		//	y=_box_y+_box_h;
		//}
		//if(x<_box_x+_box_w && y<_box_y+_box_h){
		//	x=_box_x+_box_w;
		//	y=_box_y+_box_h;
		//}
};
	
	/*if(y+vy < _box_y+_box_h && y + jiki_Y + vy > _box_y ){
		if(x +jiki_X <= _box_x && x +jiki_X + vx > _box_x){
			x = _box_x - jiki_X;
			vx = 0;
		}
		if(x >= _box_x +_box_w && x + vx < _box_x +_box_w){
			
		}
	}

	if(x+vx < _box_x+_box_w && x + jiki_X +vx >_box_x){
		if(y+jiki_Y <= _box_y && y+jiki_Y+vy > _box_y){
			
		}
		if(y > _box_y +_box_h && y + vy <=_box_y + _box_h){
			y = _box_y + _box_h;
			vy =0;
		}
	}*/




void DrawGameSelect(){
	 DrawGraph(0,0,g_select,true);

	if(CheckHitKey(KEY_INPUT_1)){
		GoGameMain();
	}

	if(CheckHitKey(KEY_INPUT_2)){
		GoGameMain1();
	}
};




//STAGE1
void DrawGameMain(){

	//DrawGraph(0,0,g_hake,true);

	


	if(flag == false){
		if(CheckHitKey(KEY_INPUT_RIGHT)){
			vx += 5;
		}
		if(CheckHitKey(KEY_INPUT_LEFT)){
			vx -= 5;
		}
		if( jump_f == true){
			if(CheckHitKey(KEY_INPUT_UP)){
				vy -=20;
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
		vx=0;
		x=0;
		y=0;
		scr_x=0;
	}
	
	///
	
	if(x>350&&scr_f==false){
		scr_x=x-350;
		scr_f=true;
	}
	if(x<=350){
	scr_f=false;
	}

	
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
	/*for(int i=0;i<16;i++){
		Collision(midori_x[i],midori_y[i],midori_X[i],midori_Y[i]);
	}*/

	//for(int i=0;i<2;i++){
	//	Collision(mushoku_x[i],mushoku_y[i],mushoku_X[i],mushoku_Y[i]);
	//}
	/*for(int i=0;i<5;i++){
		Collision(a_x[i],a_y[i],a_w,a_h);
	}*/

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
		

	if(scr_f==true){
		scr_x=x-350;
		scr_f=true;
	}
	
	
	if(x >= goal_x -30 && y >= goal_y -60  && x <= goal_x +30 && y <= goal_y + 60){
		x=0;
		y=0;
		scr_x=0;
		flag = true;
	}
	if(flag ==true){

		DrawGraph(0,0,g_clear,true);

		if(CheckHitKey(KEY_INPUT_RETURN)){
			flag = false;
		}
	}
	
	/*for(int i=0;i<16;i++ ){
		DrawBox(midori_x[i]-scr_x,midori_y[i],midori_x[i]+midori_X[i]-scr_x,midori_y[i]+midori_Y[i],GREEN,true);
	 }*/

	//for(int i=0;i<5;i++ ){
	//	DrawGraph(falsegreenbox_x[i]-scr_x,falsegreenbox_y[i],g_falsegreenbox,true);
	// }
	//for(int i=0;i<2;i++ ){
	//	DrawBox(mushoku_x[i]-scr_x,mushoku_y[i],mushoku_x[i]+mushoku_X[i]-scr_x,mushoku_y[i]+mushoku_Y[i],BLUE,true);
	// }
	//for(int i=0;i<5;i++ ){
	//	DrawGraph(a_x[i]-scr_x,a_y[i],g_a,true);
	//}
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
//STAGE2
void DrawGameMain1(){
	vx = 0;
	vy += z;
	


	if(flag == false){
		if(CheckHitKey(KEY_INPUT_RIGHT)){
			vx += 5;
		}
		if(CheckHitKey(KEY_INPUT_LEFT)){
			vx -= 5;
		}
		if( jump_f == true){
			if(CheckHitKey(KEY_INPUT_UP)){
				vy -=20;
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
		vx=0;
		x=0;
		y=0;
		scr_x=0;
	}
	
	///
	
	if(x>350&&scr_f==false){
		scr_x+=x-350;
		scr_f=true;
	}
	if(x<=350){
	scr_f=false;
	}

	

	
	x += vx;
	y += vy;
	if(scr_f==true){
		scr_x += vx;
	}
	for(int i=0;i<144;i++){
		for(int j=0;j<40;j++){
			if(masucolor[i][j]==GREEN){
			Collision(i*20,j*15,20,15);
			DrawBox(i*20-scr_x,j*15,i*20+20-scr_x,j*15+15,GREEN,true);
			}
				if(masucolor[i][j]==BLUE){
			Collision(i*20,j*15,20,15);
			DrawBox(i*20-scr_x,j*15,i*20+20-scr_x,j*15+15,BLUE,true);
			}
		}
	}
	
	
	if(x >= goal_x -30 && y >= goal_y -60  && x <= goal_x +30 && y <= goal_y + 60){
		x=0;
		y=0;
		scr_x=0;
		flag = true;
	}
	if(flag ==true){

		DrawGraph(0,0,g_clear,true);

		if(CheckHitKey(KEY_INPUT_RETURN)){
			flag = false;
		}
	}
	

	DrawGraph(goal_x2-scr_x,goal_y2,g_goal,true);
	DrawGraph(x-scr_x,y,g_person,true);	

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