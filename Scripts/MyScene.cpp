#include"Suken.h"
#include"MyScene.h"

CScene 
	TITLE,
	SELECT,
	MAIN,
	MAINEX,
	MAIN1,
    MAIN1EX,
	MAIN2,
	MAIN2EX,
	MAIN3,
	MAIN3EX,
	ASOBI,
	CLEAR;

int g_title;

int g_hake;

int g_jiki;

int g_clear;

int g_goal;

int g_person;

int g_personl;

int g_mushoku;

int g_falsegreenbox;

int g_select;

int g_1ex;
int g_2ex;
int g_3ex;
int g_4ex;
int g_asobikata;
int g_haikei;
int m_die;
int m_clear;

int g_stage[4];
int masucolor[150][40];
int masucolor2[200][40];
int masucolor3[72][86];
int masucolor4[962][1150];

void AwakeScene()
{

	Game.AddChild(&TITLE);

	TITLE.input.AddEventListener(Event.EVERY_FRAME,DrawGameTitle);
	MAIN.input.AddEventListener(Event.EVERY_FRAME,DrawGameMain);
	MAINEX.input.AddEventListener(Event.EVERY_FRAME,DrawSta1ex);
	MAIN1.input.AddEventListener(Event.EVERY_FRAME,DrawGameMain1);
    MAIN1EX.input.AddEventListener(Event.EVERY_FRAME,DrawSta2ex);
	MAIN2.input.AddEventListener(Event.EVERY_FRAME,DrawGameMain2);
	MAIN2EX.input.AddEventListener(Event.EVERY_FRAME,DrawSta3ex);
	MAIN3.input.AddEventListener(Event.EVERY_FRAME,DrawGameMain3);
	MAIN3EX.input.AddEventListener(Event.EVERY_FRAME,DrawSta4ex);
	SELECT.input.AddEventListener(Event.EVERY_FRAME,DrawGameSelect);
	CLEAR.input.AddEventListener(Event.EVERY_FRAME,DrawGameClear);
	ASOBI.input.AddEventListener(Event.EVERY_FRAME,DrawAsobi);

	g_title = LoadGraph("hiraokapic/ai.png",true);

	g_hake = LoadGraph("hiraokapic/Mesa.png",true);

	g_jiki = LoadGraph("hiraokapic/jiki.png",true);

	g_clear = LoadGraph("hiraokapic/Clear.png",true);

	g_goal = LoadGraph("hiraokapic/goal.png",true);

	g_person = LoadGraph("hiraokapic/person.png",true);

	g_personl = LoadGraph("hiraokapic/personl.png",true);
	
	g_mushoku = LoadGraph("hiraokapic/mushoku.png",true);

	g_falsegreenbox = LoadGraph("hiraokapic/falsegreenbox.png",true);

	g_select = LoadGraph("hiraokapic/select2.png",true);

	g_1ex = LoadGraph("hiraokapic/sta1ex.png",true);

	g_2ex = LoadGraph("hiraokapic/sta2ex.png",true);
	g_3ex = LoadGraph("hiraokapic/alpacaex.png",true);
	g_4ex = LoadGraph("hiraokapic/gorilla.png",true);
	g_asobikata=LoadGraph("hiraokapic/asobikata.png",true);
	g_haikei = LoadGraph("hiraokapic/ushiro.png",true);
	m_die = LoadSoundMem("hiraokapic/die.wav",true);
	m_clear = LoadSoundMem("hiraokapic/clear.wav",true);
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
g_stage[0] =LoadSoftImage("hiraokapic/gorillaaa.png"); 
	int r4,g4,b4;
	for(int i3=0;i3<962;i3++){
		for(int j3=0;j3<1150;j3++){
			GetPixelSoftImage(g_stage[0],i3,j3,&r4,&g4,&b4,0);
			masucolor4[i3][j3] = GetColor(r4,g4,b4);
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
bool scr_fx4=false;
bool scr_fy4=false;
bool flag4=false;
bool jump_f4=false;

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

int goal_x3=140;
int goal_y3=390;
const int jiki_X3= 30;
const int jiki_Y3 = 60;
int scr_x3 = 0;
int scr_y3 = 0;
int x3=815;
int y3=1155;
int vx3=0;
int vy3=0;
int z3=1;

int goal_x4=1400;
int goal_y4=225;
const int jiki_X4= 30;
const int jiki_Y4 = 60;
int scr_x4 = 0;
int scr_y4 = 0;
int x4=1800;
int y4=450;
int vx4=0;
int vy4=0;
int z4=1;

//当たり判定
void Collision(int _box_x,int _box_y,int _box_w,int _box_h){

		if(x+vx+jiki_X>_box_x && x+vx<_box_x+_box_w && y>_box_y-jiki_Y && y<_box_y+_box_h && vx>=0 ){
		
		x=_box_x-jiki_X;
		vx=0;
		}

		if(x+vx+jiki_X>_box_x+_box_w &&x+vx<_box_w+_box_x  && y>_box_y-jiki_Y && y<_box_y+_box_h  && vx<=0){
			x = _box_x + _box_w;
			vx=0;
			}

	if(x>_box_x-jiki_X && x<_box_x+_box_w && y+vy>=_box_y-jiki_Y && y+vy<_box_y+_box_h && vy>=0){
			y = _box_y - jiki_Y;
			vy=0;
			jump_f=true;
		}

	if(x>_box_x-jiki_X && x<_box_x+_box_w && y+vy<=_box_y+_box_h && y+vy>_box_y-jiki_Y && vy<=0){
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

	if(x2+vx2>_box_x-30 && x2+vx2<_box_x+_box_w && y2+vy2>=_box_y-60 && y2+vy2<_box_y+_box_h && vy2>=0){
			y2 = _box_y - jiki_Y;
			vy2=0;
			jump_f2=true;
		}

	if(x2+vx2>_box_x-30 && x2+vx2<_box_x+_box_w && y2+vy2<=_box_y+_box_h && y2+vy2>_box_y-60 && vy2<=0){
			y2 = _box_y + _box_h;
			vy2 =0;
		}
	
	
	
};
void Collision3(int _box_x,int _box_y,int _box_w,int _box_h){

		if(x3+vx3+jiki_X3>_box_x && x3+vx3<_box_x+_box_w && y3>_box_y-60 && y3<_box_y+_box_h && vx3>=0 ){
		
		x3=_box_x-jiki_X3;
		vx3=0;
		}

		if(x3+vx3+jiki_X3>_box_x+_box_w &&x3+vx3<_box_w+_box_x  && y3>_box_y-60 && y3<_box_y+_box_h  && vx3<=0){
			x3 = _box_x + _box_w;
			vx3=0;
			}

	if(x3+vx3>_box_x-30 && x3+vx3<_box_x+_box_w && y3+vy3>=_box_y-60 && y3+vy3<_box_y+_box_h && vy3>=0){
			y3 = _box_y - jiki_Y3;
			vy3=0;
			jump_f3=true;
		}

	if(x3+vx3>_box_x-30 && x3+vx3<_box_x+_box_w && y3+vy3<=_box_y+_box_h && y3+vy3>_box_y-60 && vy3<0){
			y3 = _box_y + _box_h;
			vy3 =0;
		}
	
	
	
};
void Collision4(int _box_x,int _box_y,int _box_w,int _box_h){

		if(x4+vx4+jiki_X4>_box_x && x4+vx4<_box_x+_box_w && y4>_box_y-60 && y4<_box_y+_box_h && vx4>=0 ){
		
		x4=_box_x-jiki_X4;
		vx4=0;
		}

		if(x4+vx4+jiki_X4>_box_x+_box_w &&x4+vx4<_box_w+_box_x  && y4>_box_y-60 && y4<_box_y+_box_h  && vx4<=0){
			x4 = _box_x + _box_w;
			vx4=0;
			}

	if(x4+vx4>_box_x-30 && x4+vx4<_box_x+_box_w && y4+vy4>=_box_y-60 && y4+vy4<_box_y+_box_h && vy4>=0){
			y4 = _box_y - jiki_Y4;
			vy4=0;
			jump_f4=true;
		}

	if(x4+vx4>_box_x-30 && x4+vx4<_box_x+_box_w && y4+vy4<=_box_y+_box_h && y4+vy4>_box_y-60 && vy4<=0){
			y4 = _box_y + _box_h;
			vy4 =0;
		}
	
	
	
};
//ステージ選択
void DrawGameSelect(){
	 DrawGraph(0,0,g_select,true);

	if(CheckHitKey(KEY_INPUT_1)){
		GoSta1ex();
	}

	if(CheckHitKey(KEY_INPUT_2)){
		GoSta2ex();
	}
if(CheckHitKey(KEY_INPUT_3)){
		GoSta3ex();
	}
if(CheckHitKey(KEY_INPUT_4)){
		GoSta4ex();
	}
if(CheckHitKey(KEY_INPUT_5)){
        GoAsobi();   
}
};

void DrawSta1ex(){
	DrawGraph(0,0,g_1ex,true);
		if(CheckHitKey(KEY_INPUT_RETURN)){
			GoGameMain();
		}
	};
void DrawSta2ex(){
	DrawGraph(0,0,g_2ex,true);
		if(CheckHitKey(KEY_INPUT_RETURN)){
			GoGameMain1();
		}
	};
void DrawSta3ex(){
	DrawGraph(0,0,g_3ex,true);
		if(CheckHitKey(KEY_INPUT_RETURN)){
			GoGameMain2();
		}
	};
void DrawSta4ex(){
	DrawGraph(0,0,g_4ex,true);
		if(CheckHitKey(KEY_INPUT_RETURN)){
			GoGameMain3();
		}
	};
void DrawAsobi(){
	DrawGraph(0,0,g_asobikata,true);
	if(CheckHitKey(KEY_INPUT_RETURN)){
			GoGameSelect();
		}
};

//STAGE1
void DrawGameMain(){
	DrawBox(0,0,10000,10000,BLUE,true);

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

	if(CheckHitKey(KEY_INPUT_0)){
	    x=2050;
		y=150;
		vx=0;
		vy=0;
		
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
	if(CheckHitKey(KEY_INPUT_LEFT)){
	     DrawGraph(x-scr_x,y,g_personl,true);
	}else{
		DrawGraph(x-scr_x,y,g_person,true);
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
		PlaySoundMem(m_clear,DX_PLAYTYPE_BACK,true);
	}
	if(flag ==true){

		GoGameClear();

		if(CheckHitKey(KEY_INPUT_RETURN)){
		GoGameSelect();
		}
		flag = false;
	}
	
	
	DrawGraph(goal_x-scr_x,goal_y-scr_y,g_goal,true);
	/*DrawGraph(x-scr_x,y,g_personl,true);
	DrawGraph(x-scr_x,y,g_person,true);	*/
	/*DrawBox(x-scr_x,y,x+jiki_X-scr_x,y+jiki_Y,WHITE,false);*/
	DrawFormatString(700,0,RED,"x:%d",x);
	DrawFormatString(700,20,RED,"y:%d",y);
	if(CheckHitKey(KEY_INPUT_BACK)){
		x=2050;
		y=150;

		vx=0;
		vy=0;
		GoGameSelect();
	}

};
///sta2
void DrawGameMain1(){
	DrawBox(0,0,10000,10000,YELLOW,true);
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
	if(CheckHitKey(KEY_INPUT_0)){
	    x2=1800;
		y2=40;
		vx2=0;
		vy2=0;
		
	}

	jump_f2 = false;

	if(x2+vx2 < 0 ){
		vx2=0;
		x2=0;
	}
	
	
	if(y2+vy2 > 600){
		vy2=0;
		vx2=0;
		x2=1800;
		y2=45;
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

	if(CheckHitKey(KEY_INPUT_LEFT)){
	     DrawGraph(x2-scr_x2,y2,g_personl,true);
	}else{
		DrawGraph(x2-scr_x2,y2,g_person,true);
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
		x2=1800;
		y2=40;
		scr_x2=0;
		flag2 = true;
		PlaySoundMem(m_clear,DX_PLAYTYPE_BACK,true);
	}
	if(flag2 ==true){

		GoGameClear();

		if(CheckHitKey(KEY_INPUT_RETURN)){
		GoGameSelect();
		}
		flag2 = false;
	}
	
	
	DrawGraph(goal_x2-scr_x2,goal_y2,g_goal,true);
	/*DrawGraph(x2-scr_x2,y2,g_person,true);*/	
	/*DrawBox(x2-scr_x2,y2,x2+jiki_X2-scr_x2,y2+jiki_Y2,WHITE,false);*/
	DrawFormatString(700,0,RED,"x:%d",x2);
	DrawFormatString(700,20,RED,"y:%d",y2);
	if(CheckHitKey(KEY_INPUT_BACK)){
		x2=1800;
		y2=40;

		vx2=0;
		vy2=0;
		GoGameSelect();
	}

};
//sta3
void DrawGameMain2(){
	DrawBox(0,0,10000,10000,WHITE,true);
	//ワープ
	if(x3+vx3>690&&x3+vx3<740){
		if(y3+vy3==1005){
			x3=820;
			y3=795;
			vx3=0;
			vy3=0;
			scr_x3=0;
			scr_y3=0;
			jump_f3=false;
		}}
	if(x3+vx3>630&&x3+vx3<680){
		if(y3+vy3==1020){
			x3=0;
			y3=1000;
			vx3=0;
			vy3=0;
			scr_x3=0;
			scr_y3=0;
			jump_f3=false;
		}}
	if(x3+vx3>720&&x3+vx3<=790){
		if(y3+vy3==810){
			x3=0;
			y3=1000;
			vx3=0;
			vy3=0;
			scr_x3=0;
			scr_y3=0;
			jump_f3=false;
		}}
	if(x3+vx3>650&&x3+vx3<700){
		if(y3+vy3==765){
			x3=450;
			y3=520;
			vx3=0;
			vy3=0;
			scr_x3=0;
			scr_y3=0;
			jump_f3=false;
		}}
	if(x3+vx3>=700&&x3+vx3<740){
		if(y3+vy3==795){
			x3=440;
			y3=345;
			vx3=0;
			vy3=0;
			
			jump_f3=false;
		}}
	if(x3+vx3>850&&x3+vx3<=900){
		if(y3+vy3==1125){
			x3=0;
			y3=1000;
			vx3=0;
			vy3=0;
			scr_x3=0;
			scr_y3=0;
			jump_f3=false;
		}}
	if(x3+vx3>570&&x3+vx3<=620){
		if(y3+vy3==735){
			x3=500;
			y3=400;
			vx3=0;
			vy3=0;
			scr_x3=0;
			scr_y3=0;
			jump_f3=false;
		}}
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
	if(CheckHitKey(KEY_INPUT_0)){
	    x3=815;
		y3=1155;
		vx3=0;
		vy3=0;
		
	}

	jump_f3 = false;

	if(x3+vx3 < 0 ){
		vx3=0;
		x3=0;
	}
	
	
	if(y3+vy3 > 1300){
		vy3=0;
		x3=815;
		vx3=0;
		y3=1155;
		
	}
	
	
	
	for(int i2=0;i2<72;i2++){
		for(int j2=0;j2<86;j2++){
			if(masucolor3[i2][j2]==BLACK){
			Collision3(i2*20,j2*15,20,15);
			DrawBox(i2*20-scr_x3,j2*15-scr_y3,i2*20+20-scr_x3,j2*15+15-scr_y3,BLACK,true);
			}
			if(masucolor3[i2][j2]==WHITE){
			DrawBox(i2*20-scr_x3,j2*15-scr_y3,i2*20+20-scr_x3,j2*15+15-scr_y3,WHITE,true);
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
	if(CheckHitKey(KEY_INPUT_LEFT)){
	     DrawGraph(x3-scr_x3,y3-scr_y3,g_personl,true);
	}else{
		DrawGraph(x3-scr_x3,y3-scr_y3,g_person,true);
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
		x3=815;
		y3=1155;
		vx3=0;
		vy3=0;
		scr_x3=0;
		scr_y3=0;
		flag3= true;
		PlaySoundMem(m_clear,DX_PLAYTYPE_BACK,true);
	}
	if(flag3 ==true){

		GoGameClear();
	}
		if(CheckHitKey(KEY_INPUT_BACK)){
		GoGameSelect();
		}
		flag3 = false;
	
	
	
	DrawGraph(goal_x3-scr_x3,goal_y3-scr_y3,g_goal,true);
	/*DrawGraph(x3-scr_x3,y3-scr_y3,g_person,true);*/	
	/*DrawBox(x3-scr_x3,y3-scr_y3,x3+jiki_X3-scr_x3,y3+jiki_Y3-scr_y3,WHITE,false);*/
	DrawFormatString(700,0,RED,"x:%d",x3);
	DrawFormatString(700,20,RED,"y:%d",y3);
	if(CheckHitKey(KEY_INPUT_BACK)){
		x3=815;
		y3=1155;
		scr_x3=0;
		scr_y3=0;
		vx3=0;
		vy3=0;
		GoGameSelect();
	}

};
//sta4
void DrawGameMain3(){
	DrawBox(0,0,10000,10000,GREEN,true);
	//1
	if(x4+vx4>1910&&x4+vx4<=1930){
		if(y4+vy4==465){
			x4=1900;
			y4=2250;
			vx4=0;
			vy4=0;
			scr_x4=0;
			scr_y4=0;
			jump_f4=false;
		}}
	//2
	if(x4+vx4>1670&&x4+vx4<1720){
		if(y4+vy4==465){
			x4=3320;
			y4=3000;
			vx4=0;
			vy4=0;
			scr_x4=0;
			scr_y4=0;
			jump_f4=false;
		}}
	//3
	if(x4+vx4>3230&&x4+vx4<3280){
		if(y4+vy4==2985){
			x4=2200;
			y4=1580;
			vx4=0;
			vy4=0;
			scr_x4=0;
			scr_y4=0;
			jump_f4=false;
		}}
	//4
	if(x4+vx4>2170&&x4+vx4<2220){
		if(y4+vy4==1410){
			x4=1900;
			y4=2250;
			vx4=0;
			vy4=0;
			scr_x4=0;
			scr_y4=0;
			jump_f4=false;
		}}
	//5
	if(x4+vx4>2090&&x4+vx4<2140){
		if(y4+vy4==1200){
			x4=1900;
			y4=2250;
			vx4=0;
			vy4=0;
			scr_x4=0;
			scr_y4=0;
			jump_f4=false;
		}}
	//6
	if(x4+vx4>1990&&x4+vx4<2040){
		if(y4+vy4==1035){
			x4=1900;
			y4=2250;
			vx4=0;
			vy4=0;
			scr_x4=0;
			scr_y4=0;
	jump_f4=false;
		}}
	//7
	if(x4+vx4>1830&&x4+vx4<1880){
		if(y4+vy4==1095){
			x4=1300;
			y4=1050;
			vx4=0;
			vy4=0;
			scr_x4=0;
			scr_y4=0;
			jump_f4=false;
		}}
	//8
	if(x4+vx4>1910&&x4+vx4<1960){
		if(y4+vy4==1275){
			x4=2000;
			y4=900;
			vx4=0;
			vy4=0;
			scr_x4=0;
			scr_y4=0;
			jump_f4=false;
		}}
	//9
	if(x4+vx4>1990&&x4+vx4<2040){
		if(y4+vy4==1500){
			x4=400;
			y4=1500;
			vx4=0;
			vy4=0;
			scr_x4=0;
			scr_y4=0;
			jump_f4=false;
		}}
		//10
		if(x4+vx4>1930&&x4+vx4<1980){
		if(y4+vy4==1680){
			x4=1540;
			y4=2910;
			vx4=0;
			vy4=0;
			scr_x4=0;
			scr_y4=0;
			jump_f4=false;
		}}
      //11
		if(x4+vx4>1370&&x4+vx4<1420){
		if(y4+vy4==855){
			x4=1800;
			y4=450;
			vx4=0;
            scr_x4=0;
			scr_y4=0;
			vy4=0;
			jump_f4=false;
		}}
		//12
	if(x4+vx4>1970&&x4+vx4<2020){
		if(y4+vy4==690){
			x4=1900;
			y4=2250;
			vx4=0;
			vy4=0;
			scr_x4=0;
			scr_y4=0;
			jump_f4=false;
		}}
	//13
	if(x4+vx4>790&&x4+vx4<810){
		if(y4+vy4==1290){
			x4=1900;
			y4=2250;
			vx4=0;
			vy4=0;
			scr_x4=0;
			scr_y4=0;
		jump_f4=false;
		}}
	//14
	if(x4+vx4>410&&x4+vx4<460){
		if(y4+vy4==660){
			x4=1880;
			y4=1950;
			vx4=0;
			vy4=0;
			scr_x4=0;
			scr_y4=0;
			jump_f4=false;
		}}
	//15
	if(x4+vx4>110&&x4+vx4<160){
		if(y4+vy4==1440){
			x4=600;
			y4=450;
			vx4=0;
			vy4=0;
			scr_x4=0;
			scr_y4=0;
			jump_f4=false;
		}}
	//16
	if(x4+vx4>1630&&x4+vx4<1680){
		if(y4+vy4==2955){
			x4=2380;
			y4=405;
			vx4=0;
			vy4=0;
			scr_x4=0;
			scr_y4=0;
			jump_f4=false;
		}}
	//17
	if(x4+vx4>770&&x4+vx4<820){
		if(y4+vy4==360){
			x4=3060;
			y4=1050;
			vx4=0;
			vy4=0;
			scr_x4=0;
			scr_y4=0;
			jump_f4=false;
		}}
	//18
	if(x4+vx4>2310&&x4+vx4<2360){
		if(y4+vy4==570){
			x4=1900;
			y4=2250;
			vx4=0;
			vy4=0;
			scr_x4=0;
			scr_y4=0;
			jump_f4=false;
		}}
	//18a
	if(x4+vx4>2330&&x4+vx4<2380){
		if(y4+vy4==750){
			x4=1900;
			y4=2250;
			vx4=0;
			vy4=0;
			scr_x4=0;
			scr_y4=0;
			jump_f4=false;
		}}
	//19
	if(x4+vx4>=2600&&x4+vx4<2620){
		if(y4+vy4==1005){
			x4=1900;
			y4=2250;
			vx4=0;
			vy4=0;
			scr_x4=0;
			scr_y4=0;
			jump_f4=false;
		}}
	//20
	if(x4+vx4>3490&&x4+vx4<3540){
		if(y4+vy4==705){
			x4=3320;
			y4=3000;
			vx4=0;
			vy4=0;
			scr_x4=0;
			scr_y4=0;
			jump_f4=false;
		}}
	//21
	if(x4+vx4>2230&&x4+vx4<2280){
		if(y4+vy4==2235){
			x4=1900;
			y4=2250;
			vx4=0;
			vy4=0;
			scr_x4=0;
			scr_y4=0;
			jump_f4=false;
		}}
	//22
	if(x4+vx4>2850&&x4+vx4<2900){
		if(y4+vy4==2880){
			x4=1200;
			y4=160;
			vx4=0;
			vy4=0;
			scr_x4=0;
			scr_y4=0;
			jump_f4=false;
		}}
	//23
	if(x4+vx4>1050&&x4+vx4<1100){
		if(y4+vy4==345){
			x4=1900;
			y4=2250;
			vx4=0;
			vy4=0;
			scr_x4=0;
			scr_y4=0;
			jump_f4=false;
		}}
	//24
	if(x4+vx4>1310&&x4+vx4<1360){
		if(y4+vy4==495){
			x4=1660;
			y4=120;
			vx4=0;
			vy4=0;
			scr_x4=0;
			scr_y4=0;
			jump_f4=false;
		}}
	//25
	if(x4+vx4>1470&&x4+vx4<1520){
		if(y4+vy4==2700){
			x4=1900;
			y4=2250;
			vx4=0;
			vy4=0;
			scr_x4=0;
			scr_y4=0;
			jump_f4=false;
		}}
	//26
	if(x4+vx4>830&&x4+vx4<880){
		if(y4+vy4==780){
			x4=1900;
			y4=2250;
			vx4=0;
			vy4=0;
			scr_x4=0;
			scr_y4=0;
			jump_f4=false;
		}}
	flag4 = false;

	if(flag4 == false){
		if(CheckHitKey(KEY_INPUT_RIGHT)){
			vx4 += 5;
		}
		if(CheckHitKey(KEY_INPUT_LEFT)){
			vx4-= 5;
		}
		if( jump_f4 == true){
			if(CheckHitKey(KEY_INPUT_UP)){
				vy4 -=14;
				jump_f4 = false;
			}
		}
	}
	if(CheckHitKey(KEY_INPUT_0)){
	    x4=1800;
		y4=450;
		vx4=0;
		vy4=0;
		
	}

	jump_f4 = false;

	if(x4+vx4 < 0 ){
		vx4=0;
		x4=0;
	}
	
	
	if(y4+vy4 > 5000){
		vy4=0;
		x4=1800;
		vx4=0;
		y4=450;
		scr_x4=0;
		scr_y4=0; 
		PlaySoundMem(m_die,DX_PLAYTYPE_BACK,true);
	}
	
	



	for(int i3=0;i3<962;i3++){
		for(int j3=0;j3<1150;j3++){
			if(masucolor4[i3][j3]==BLACK){
			Collision4(i3*20,j3*15,20,15);
			DrawBox(i3*20-scr_x4,j3*15-scr_y4,i3*20+20-scr_x4,j3*15+15-scr_y4,BLACK,true);
			}
			if(masucolor4[i3][j3]==YELLOW){
			DrawBox(i3*20-scr_x4,j3*15-scr_y4,i3*20+20-scr_x4,j3*15+15-scr_y4,YELLOW,true);
			}
			if(masucolor4[i3][j3]==RED){
			Collision4(i3*20,j3*15,20,15);
			DrawBox(i3*20-scr_x4,j3*15-scr_y4,i3*20+20-scr_x4,j3*15+15-scr_y4,RED,true);
			}
	}
	}

	x4 += vx4;
	y4 += vy4;
	vx4=0;
	

	if(jump_f4==false){
		vy4+=z4;
	}else{
		if(vy4!=0){
			vy4=0;
		}
	}
	if(CheckHitKey(KEY_INPUT_LEFT)){
	     DrawGraph(x4-scr_x4,y4-scr_y4,g_personl,true);
	}else{
		DrawGraph(x4-scr_x4,y4-scr_y4,g_person,true);
	}
		
	if(x4>350&&scr_fx4==false){
		scr_x4=x4-350;
		scr_fx4=true;
	}
	if(x4<=350){
	scr_fx4=false;
	}
	if(scr_fx4==true){
		scr_x4=x4-350;
		scr_fx4=true;
	} 

		
	if(y4>300&&scr_fy4==false){
		scr_y4=y4-300;
		scr_fy4=true;
	}
	if(y4<=300){
	scr_fy4=false;
	}
	if(scr_fy4==true){
	scr_y4=y4-300;
	scr_fy4=true;
	}
	
	
	if(x4 >= goal_x4 -30 && y4 >= goal_y4 -60  && x4 <= goal_x4 +30 && y4 <= goal_y4 + 60){
		x4=1800;
		y4=450;
		vx4=0;
		vy4=0;
		scr_x4=0;
		scr_y4=0;
		flag4= true;
		PlaySoundMem(m_clear,DX_PLAYTYPE_BACK,true);
	}
	if(flag4 ==true){

		GoGameClear();
	}
		if(CheckHitKey(KEY_INPUT_BACK)){
		GoGameSelect();
		}
		flag4 = false;
	
	
	
	DrawGraph(goal_x4-scr_x4,goal_y4-scr_y4,g_goal,true);
	/*DrawGraph(x3-scr_x3,y3-scr_y3,g_person,true);*/	
	/*DrawBox(x4-vx4-scr_x4,y4-vy4-scr_y4,x4+jiki_X4,y4+jiki_Y4-vy4-scr_y4,WHITE,false);*/
	DrawFormatString(700,0,RED,"x:%d",x4);
	DrawFormatString(700,20,RED,"y:%d",y4);
	if(CheckHitKey(KEY_INPUT_BACK)){
		x4=1800;
		y4=450;
		scr_x4=0;
		scr_y4=0;
		vx4=0;
		vy4=0;
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
void GoSta1ex(){
	
	Game.RemoveChild();
	Game.AddChild(&MAINEX);
}
void GoGameSelect(){
	
	Game.RemoveChild();
	Game.AddChild(&SELECT);
}

void GoGameMain1(){
	
	Game.RemoveChild();
	Game.AddChild(&MAIN1);
}
void GoSta2ex(){
	
	Game.RemoveChild();
	Game.AddChild(&MAIN1EX);
}
void GoGameMain2(){
	
	Game.RemoveChild();
	Game.AddChild(&MAIN2);
}
void GoSta3ex(){
	
	Game.RemoveChild();
	Game.AddChild(&MAIN2EX);
}
void GoGameMain3(){
	
	Game.RemoveChild();
	Game.AddChild(&MAIN3);
}
void GoSta4ex(){
	
	Game.RemoveChild();
	Game.AddChild(&MAIN3EX);
}
void GoGameClear(){
	
	Game.RemoveChild();
	Game.AddChild(&CLEAR);
}
void GoAsobi(){
	
	Game.RemoveChild();
	Game.AddChild(&ASOBI);
}