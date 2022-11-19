//include libraries in cpp file
#include "mbed.h"
#include "MPU6050.h"
//creating an object of serial class
//so that we can communicate with PC
Serial pc(SERIAL_TX, SERIAL_RX);
Serial bt(PC_10,PC_11);
//setting LED1 to give digital output
DigitalOut myled(LED1);
//creating onject of MPU6050 class
MPU6050 ark(PB_9,PB_8);





int main()
{
    bt.baud(9600);

    while(1) {
        float acce[3];
        ark.getAccelero(acce);

        float pos1=acce[0];
        float pos2=acce[1];
        float pos3=acce[2];

        if((pos1>0.2&&pos1<2.97)&&(pos2<0.2&&pos2>-1.08)&&(pos3>8&&pos3<9.4)) {
            pc.printf("freno");
            bt.putc('F');
        }
        if((pos1>-5.2&&pos1<-0.09)) {
            pc.printf("adel");
            bt.putc('W');
        }
        if((pos1<9.5&&pos1>3)) {
            pc.printf("atras");
            bt.putc('S');
        }


        if ((pos2>2&&pos2<8)) {
            pc.printf("der\r\n");
            bt.putc('D');
        }

        if((pos2>-9&&pos2<-1.5))

        {
            pc.printf("izq\r\n");
            bt.putc('A');
        }


        pc.printf("pos1=%f,pos2=%f,pos3=%f\r\n",acce[0],acce[1],acce[2]);
        wait_ms(300); //wait 1000ms


    }
}