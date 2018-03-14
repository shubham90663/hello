#include <iostream>

using namespace std;
class ManualTransmission
{
    int current_speed;
    int gear;
    char R_gear;

public:
    ManualTransmission()
    {
        current_speed=30;
        gear=0;
    }
    ~ManualTransmission()
    {

    }
    int SetGear(int gear_val)
    {
        gear=gear_val;
        if(1==gear || 2==gear)
        return 1;
        else
            return 0;
    }
    int SetGear(char gear_val)
    {
        if('R'== gear_val || 'r'==gear_val)
        {
         R_gear=gear_val;

            return 1;
        }
        else
            return 0;
    }
    int SetSpeed(int s)
    {

        current_speed=s;
        return current_speed;
    }
    int IncSpeed(int i)
    {

        current_speed = current_speed+i;
        return current_speed;
    }

    int DecSpeed(int d)
    {
        current_speed = current_speed-d;
        return current_speed;
    }

friend class AutoTransmission;
};

class AutoTransmission
{
    public:
        int set_speed;

    AutoTransmission()
    {
        set_speed=0;
    }
    ~AutoTransmission()
    { }
    int Set_autogear(ManualTransmission& obj,int g)
    {
        obj.SetGear(g);

        return obj.gear;
    }
    char Set_autogear(ManualTransmission& obj,char g)
    {
        obj.SetGear(g);
        return obj.R_gear;
    }

    int Set_autospeed(ManualTransmission& obj,int s)
    {
        set_speed=s;
        obj.SetSpeed(s);
        return obj.current_speed;
    }
    int Inc_autospeed(ManualTransmission& obj,int i)
    {
        if((obj.current_speed<set_speed) && ((set_speed-obj.current_speed)>=10)){
        obj.IncSpeed(i);

        return obj.current_speed;
        }
        else
            return -1;

    }

    int Dec_autospeed(ManualTransmission& obj,int d)
    {
        if(obj.current_speed>0 &&(obj.current_speed>=d)){
        obj.DecSpeed(d);

        return obj.current_speed;
        }
        else
            return -1;
    }


};
int main()
{
    int EngineStatus=0;
    ManualTransmission mt;
    AutoTransmission aut;
    int EngineStatus_input=0;
    unsigned char TransmissionMode;
    int choice=0;
    int gear_mode=0;
    int speed=0;
    int inc_speed=0;
    int dec_speed=0;
    bool HdcStatus=false;

    cout<<"********ENGINE STATUS*********"<<endl;
    cout<<"PRESS THE FOLLOWING"<<endl;

    cout<<"ENGINE ON --> 1"<<"    "<< "ENGINE OFF --> 0"<<endl;
    cin>>EngineStatus_input;
    EngineStatus=EngineStatus_input;

    if(0==EngineStatus)
    {
        cout<<" The engine is switched OFF "<<endl;
    }
    else if(1==EngineStatus)
    {
        cout<<"engine is switched ON"<<endl;
        cout<<endl;
        cout<< "MANUAL MODE --> M"<<"    "<<"AUTO MODE --> A"<<endl;
        cin>>TransmissionMode;
        if('M'==TransmissionMode || 'm'==TransmissionMode)
        {
            bool In_gear_manual=false;
            cout<< " Manual mode switched ON"<<endl;
            do{

            cout<<endl;
            cout<< "<[  1. SWITCH ON HDC MANUALLY\n    2. SET SPEED\n    3. INCREASE SET SPEED\n    4. DECREASE SET SPEED\n    5. SWITCH OFF HDC]>"<<endl;
            cout<<endl;
            cout<<" ENTER COMMAND FOR OPERATION"<<endl;
            cin>>choice;
            if(1==choice)
            {
                if(1==HdcStatus)
                    cout<<" HDC ALREADY IN MANUAL MODE"<<endl;
                else{
                cout<<" HDC MANUALLY SWITCHED ON"<<endl;
                HdcStatus=choice;
                cout<<HdcStatus;
                cout<<" ENTER THE GEAR(1,2)  FOR REVERSE ENTER -1 "<<endl;

                cin>>gear_mode;
                if(1==gear_mode || 2==gear_mode)
                {
                int ret_gear=mt.SetGear(gear_mode);
                In_gear_manual=true;
                cout<<" Vehicle in gear no. "<<gear_mode<<endl;
                cout<<endl;
                if(ret_gear==0)
                {

                    cout<<" HDC cannot be implemented in this gear"<<endl;
                    break;
                }
                }
                else if(-1 == gear_mode)
                {
                    int ret_gear=mt.SetGear('r');
                    In_gear_manual=true;
                    if(ret_gear==0)
                    {

                    cout<<" HDC cannot be implemented in this gear"<<endl;
                    break;
                    }

                }
                }

            }
            else if(2==choice)
            {
                if(In_gear_manual==true){
                cout<<" SET SPEED"<<endl;
                cin>>speed;
                int ret_speed=mt.SetSpeed(speed);
                cout<<" Current Vehicle Speed is set to "<<ret_speed<<endl;
                }
                else{
                    cout<<"vehicle not in gear"<<endl;
                    break;}

            }
            else if(3==choice)
            {
                cout<<"ENTER VALUE OF INCREASE IN SPEED"<<endl;
                cin>>inc_speed;
                int ret_incspeed=mt.IncSpeed(inc_speed);
                cout<< " Speed after increment is "<<ret_incspeed<<endl;

            }
            else if(4==choice)
            {

                cout<<"DECREASE SET SPEED"<<endl;
                cin>>dec_speed;
                int ret_decspeed=mt.DecSpeed(dec_speed);
                cout<<" speed after deceleration is "<<ret_decspeed<<endl;
            }
            else if(5==choice)
            {
                cout<<"MANUAL HDC SWITCHED OFF"<<endl;
                HdcStatus=0;
                 break;
            }
            else
            {
                cout<<"invalid input "<<endl;

            }
        }while(1);

        }


        else if('A'==TransmissionMode || 'a' ==TransmissionMode)
        {
            bool In_gear_auto=false;
            cout<<" Auto mode switched ON"<<endl;

            do{
            cout<< "1. SWITCH ON AUTO HDC MODE \n  2.SET SPEED \n 3. ACCELERATE \n  4. DECCELERATE \n 5. exit"<<endl;
            cout<<endl;
            cout<<"ENTER COMMAND FOR OPERATION"<<endl;
            cin>>choice;
            if(1==choice)
            {
                if(1==HdcStatus)
                    cout<<" HDC ALREADY IN AUTO MODE"<<endl;
                else
                {
                    cout<<"AUTO HDC SWITCHED ON"<<endl;
                    HdcStatus=choice;
                       cout<<" ENTER THE GEAR(1,2)  FOR REVERSE ENTER -1 "<<endl;

                cin>>gear_mode;
                if(1==gear_mode || 2==gear_mode)
                {
                int ret_gear=aut.Set_autogear(mt,gear_mode);
                In_gear_auto=true;
                cout<<" In Gear no. "<<gear_mode<<endl;
                if(ret_gear==0)
                {

                    cout<<" HDC cannot be implemented in this gear"<<endl;

                }
                }
                 else if(-1 == gear_mode)
                {
                    char ret_Rgear=aut.Set_autogear(mt,'r');
                    In_gear_auto=true;
                    cout<< "In reverse gear "<<endl;
                    if(ret_Rgear==0)
                    {

                    cout<<" HDC cannot be implemented in this gear"<<endl;

                    }

                }
                }

                }


            else if(2==choice)
            {
                if(In_gear_auto==true){
                cout<<" SET SPEED"<<endl;
                cin>>speed;
                int ret_speed=aut.Set_autospeed(mt,speed);
                cout<<" Current Vehicle Speed is set to "<<ret_speed<<endl;
                }
                else{
                    cout<<"vehicle not in gear"<<endl;
                    }
            }
            else if(3==choice)
            {
                if(In_gear_auto==true){
                        cout<<" Enter the amount of acceleration"<<endl;
                cin>>inc_speed;
                int ret_speed=aut.Inc_autospeed(mt,inc_speed);
                if(-1==ret_speed)
                    cout<<" Vehicle cannot be accelerated beyond set speed"<<endl;
                else
                    cout<<" Vehicle Current Speed is "<<ret_speed<<endl;

            }
            else{cout<<"vehicle not in gear"<<endl;break;}
            }

            else if(4==choice)
            {
                if(In_gear_auto==true){
                        cout<<"Enter the amount of deceleration "<<endl;
                cin>>dec_speed;
                int ret_speed=aut.Dec_autospeed(mt,dec_speed);
                 if(-1==ret_speed)
                    cout<<" Vehicle cannot be decelerated more"<<endl;
                else
                    cout<<" Vehicle Current Speed is "<<ret_speed<<endl;
                }
                else{cout<<"vehicle not in gear"<<endl;break;}
            }

            else if(5==choice)
            {
                cout<<"AUTO HDC SWITCHED OFF"<<endl;
                HdcStatus=0;
                 break;
            }
            else
            {
                cout<<"invalid input "<<endl;

            }


        }while(1);
        }

    }

    return 0;
}
