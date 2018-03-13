#include <iostream>
#include<time.h>

using namespace std;
class pre_coll{
public:


    int vechile_no;
    int speed;
    int res;

        int radar_dis;
pre_coll(int radar=80,int vechile=66,int sped=90){
radar_dis=radar;
vechile_no=vechile;
speed=sped;
}
void alert();
void dis_mod();
void sound_alert();
void visual_alert();
void braking();
void response_check();
void deaccelerate();
void accelerate();
void dis_speed();
void speed_cont();
};

class ped : pre_coll{

void sound_alert();
void braking();
void deaccelerate();
void accelerate();
};

void pre_coll :: dis_mod(){
if(radar_dis<10)
    radar_dis=0;
else
radar_dis=radar_dis - 10;
}
void pre_coll :: response_check(){
int z;
cout<<"Please type 1 to respond"<<endl;
cin>>z;
if (z==1)
    cout<<"Driver Active"<<endl;
else
   speed=0;
}


void pre_coll :: speed_cont(){

     if(radar_dis < 20)
    speed=20;
else if(radar_dis> 20 && radar_dis <50)
    speed=40;

}

void pre_coll :: accelerate(){

     if(radar_dis < 20 || speed <20)
        speed=speed+5;
else if((radar_dis>= 20 && radar_dis <50) || (speed>= 20 && speed <50))
    speed=speed + 10;
else if(( radar_dis >=50 && radar_dis <200) || (speed>= 50 && speed <200))
    speed=speed + 20;
    else
        speed=200;

}

void pre_coll :: deaccelerate(){

    if(speed<=5)
        speed=0;
    else if(radar_dis < 20 || speed <20)
    speed=speed - 5;
else if((radar_dis>= 20 && radar_dis <50) ||(speed>= 20 && speed <50))
    speed=speed - 10;
else if(( radar_dis >=50 && radar_dis<200) ||( speed >=50 && speed<200))
    speed=speed - 20;
    else
        speed=speed-50;

}


void pre_coll ::braking(){

speed=0;
}
void pre_coll :: dis_speed(){

cout<<"Current Vehicle speed = "<<speed<<endl;
}
void pre_coll ::alert(){
if(radar_dis <100)
    {
    sound_alert();
    visual_alert();

    }
   }

void pre_coll :: sound_alert(){
if(radar_dis<100 && radar_dis>50)
    cout<<"low vol warning"<<endl;
else if(radar_dis<50 && radar_dis >25)
    cout<<"med vol warning"<<endl;
    else if(radar_dis <25)
    cout<<"High vol warning"<<endl;

}
void pre_coll :: visual_alert(){

if(radar_dis<100 && radar_dis>50)
    cout<<"Obstacle in range 100m"<<endl;
else if(radar_dis<50 && radar_dis >25)
    cout<<"Obstacle in range 50m"<<endl;
    else if(radar_dis <25)
    cout<<"Obstacle in range less than 25m"<<endl;
}


int main()
{
pre_coll v1;
int ch;


do{

    cout<<"1. Display Dashboard\n2. Accelerate\n3. DeAccelerate\n4. Brake\n5. exit"<<endl;
    cin>>ch;

    if(ch==1)
        v1.dis_speed();
    else if(ch==2)
{
             v1.accelerate();
             v1.dis_speed();
}

    else if(ch==3){
        v1.deaccelerate();
        v1.dis_speed();
        }
    else if(ch==4)
        v1.braking();
    else if(ch==5)
        break;
    else
        cout<<"Invalid Input";
    v1.dis_mod();
    if(v1.radar_dis<100 && v1.speed >20){
    v1.speed_cont();
    v1.alert();
    v1.response_check();
    }
}while(1);

}
