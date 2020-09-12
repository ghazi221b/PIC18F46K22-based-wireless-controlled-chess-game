  sbit LCD_RS at RD0_bit;
sbit LCD_EN at RD1_bit;
sbit LCD_D4 at RD2_bit;
sbit LCD_D5 at RD3_bit;
sbit LCD_D6 at RD4_bit;
sbit LCD_D7 at RD5_bit;
sbit LCD_RS_Direction at TRISD0_bit;
sbit LCD_EN_Direction at TRISD1_bit;
sbit LCD_D4_Direction at TRISD2_bit;
sbit LCD_D5_Direction at TRISD3_bit;
sbit LCD_D6_Direction at TRISD4_bit;
sbit LCD_D7_Direction at TRISD5_bit;
struct piece{
char name;
unsigned short x;
unsigned short y;
unsigned short empty;
unsigned short color;
unsigned short status;
};

struct piece board[8][8];
int i=0;
int j=0;
unsigned short inity,finy;
char initx,finx;
int calib=0;// value that moves motor by half step
float yvalue;
float xvalue;
float counter=0;
short aa;
unsigned short movechecker(unsigned short ix,unsigned short iy,unsigned short dx,unsigned short dy);
void init()
{
//row0
 board[0][0].name='r'; board[0][0].x=0;board[0][0].y=0; board[0][0].empty=0; board[0][0].color=1;
 board[0][1].name='h'; board[0][1].x=0;board[0][1].y=1; board[0][1].empty=0; board[0][1].color=1;
 board[0][2].name='b'; board[0][2].x=0;board[0][2].y=2; board[0][2].empty=0; board[0][2].color=1;
 board[0][3].name='q'; board[0][3].x=0;board[0][3].y=3; board[0][3].empty=0; board[0][3].color=1;
 board[0][4].name='k'; board[0][4].x=0;board[0][4].y=4; board[0][4].empty=0; board[0][4].color=1;
 board[0][5].name='b'; board[0][5].x=0;board[0][5].y=5; board[0][5].empty=0; board[0][5].color=1;
 board[0][6].name='h'; board[0][6].x=0;board[0][6].y=6; board[0][6].empty=0; board[0][6].color=1;
 board[0][7].name='r'; board[0][7].x=0;board[0][7].y=7; board[0][7].empty=0; board[0][7].color=1;
 //row1
 board[1][0].name='p'; board[1][0].x=1;board[1][0].y=0; board[1][0].empty=0; board[1][0].color=1; board[1][0].status=0;
 board[1][1].name='p'; board[1][1].x=1;board[1][1].y=1; board[1][1].empty=0; board[1][1].color=1; board[1][1].status=0;
 board[1][2].name='p'; board[1][2].x=1;board[1][2].y=2; board[1][2].empty=0; board[1][2].color=1; board[1][2].status=0;
 board[1][3].name='p'; board[1][3].x=1;board[1][3].y=3; board[1][3].empty=0; board[1][3].color=1; board[1][3].status=0;
 board[1][4].name='p'; board[1][4].x=1;board[1][4].y=4; board[1][4].empty=0; board[1][4].color=1; board[1][4].status=0;
 board[1][5].name='p'; board[1][5].x=1;board[1][5].y=5; board[1][5].empty=0; board[1][5].color=1; board[1][5].status=0;
 board[1][6].name='p'; board[1][6].x=1;board[1][6].y=6; board[1][6].empty=0; board[1][6].color=1; board[1][6].status=0;
 board[1][7].name='p'; board[1][7].x=1;board[1][7].y=7; board[1][7].empty=0; board[1][7].color=1; board[1][7].status=0;
 //row2
 board[2][0].empty=1;
 board[2][1].empty=1;
 board[2][2].empty=1;
 board[2][3].empty=1;
 board[2][4].empty=1;
 board[2][5].empty=1;
 board[2][6].empty=1;
 board[2][7].empty=1;
 //row 3
 board[3][0].empty=1;
 board[3][1].empty=1;
 board[3][2].empty=1;
 board[3][3].empty=1;
 board[3][4].empty=1;
 board[3][5].empty=1;
 board[3][6].empty=1;
 board[3][7].empty=1;
 //row 4
 board[4][0].empty=1;
 board[4][1].empty=1;
 board[4][2].empty=1;
 board[4][3].empty=1;
 board[4][4].empty=1;
 board[4][5].empty=1;
 board[4][6].empty=1;
 board[4][7].empty=1;
 //row 5
 board[5][0].empty=1;
 board[5][1].empty=1;
 board[5][2].empty=1;
 board[5][3].empty=1;
 board[5][4].empty=1;
 board[5][5].empty=1;
 board[5][6].empty=1;
 board[5][7].empty=1;
 //row 6
 board[6][0].name='p'; board[6][0].x=6;board[6][0].y=0; board[6][0].empty=0; board[6][0].color=0;board[6][0].status=0;
 board[6][1].name='p'; board[6][1].x=6;board[6][1].y=1; board[6][1].empty=0; board[6][1].color=0;board[6][1].status=0;
 board[6][2].name='p'; board[6][2].x=6;board[6][2].y=2; board[6][2].empty=0; board[6][2].color=0;board[6][2].status=0;
 board[6][3].name='p'; board[6][3].x=6;board[6][3].y=3; board[6][3].empty=0; board[6][3].color=0;board[6][3].status=0;
 board[6][4].name='p'; board[6][4].x=6;board[6][4].y=4; board[6][4].empty=0; board[6][4].color=0;board[6][4].status=0;
 board[6][5].name='p'; board[6][5].x=6;board[6][5].y=5; board[6][5].empty=0; board[6][5].color=0;board[6][5].status=0;
 board[6][6].name='p'; board[6][6].x=6;board[6][6].y=6; board[6][6].empty=0; board[6][6].color=0;board[6][6].status=0;
 board[6][7].name='p'; board[6][7].x=6;board[6][7].y=7; board[6][7].empty=0; board[6][7].color=0;board[6][7].status=0;
 //row 7
 board[7][0].name='r'; board[7][0].x=7;board[7][0].y=0; board[7][0].empty=0; board[7][0].color=0;
 board[7][1].name='h'; board[7][1].x=7;board[7][1].y=1; board[7][1].empty=0; board[7][1].color=0;
 board[7][2].name='b'; board[7][2].x=7;board[7][2].y=2; board[7][2].empty=0; board[7][2].color=0;
 board[7][3].name='k'; board[7][3].x=7;board[7][3].y=3; board[7][3].empty=0; board[7][3].color=0;
 board[7][4].name='q'; board[7][4].x=7;board[7][4].y=4; board[7][4].empty=0; board[7][4].color=0;
 board[7][5].name='b'; board[7][5].x=7;board[7][5].y=5; board[7][5].empty=0; board[7][5].color=0;
 board[7][6].name='h'; board[7][6].x=7;board[7][6].y=6; board[7][6].empty=0; board[7][6].color=0;
 board[7][7].name='r'; board[7][7].x=7;board[7][7].y=7; board[7][7].empty=0; board[7][7].color=0;

}
void on(unsigned short on1)
{
     if(on1==1)
     {
     PORTB.b1=1;
     }
     else
     {
     PORTB.b1=0;
     }

}


void motor1(float x)//controls x axis in terms of calib x can be 1,2,3... times calibs
{   if(x<0)
{
 PORTB.b5=1;
 x=x*-1;
}
else
{
PORTB.b5=0;
}
     while(counter<x*calib)
 {
 PORTB.b7=~PORTB.b7;
 delay_us(25);
 counter=counter+1;

    }
    counter=0;
//PORTB.b5=0;
}
void motor2(float y)//controls y axis in terms of calib y can be 1,2,3... times calibs
{if(y<0)
{
PORTB.b4=0;
y=y*-1;
}
else
{
PORTB.b4=1;
}
while(counter<(y*calib))
 {
 PORTB.b6=~PORTB.b6;
 delay_us(25);
 counter=counter+1;
}
counter=0;
//PORTB.b4=0;
}

void move(unsigned short x1,unsigned short y1,unsigned short x2,unsigned short y2)
{
int a=0;
int b=0;
    if(x1==x2)
    {
    motor1(1);
    a--;
    }
   else if(x2>x1)
       {    motor1(-1);
            a--;
       }
   else if(x2<x1)
       {     motor1(1);
             a++;
       }

       //
   if(y2==y1)
    {
    motor2(1);
    b--;
    }
   else if(y2>y1)
   {  motor2(-1);
   b--;
   }
   else if(y2<y1)
   {
    motor2(1);
     b++;
   }

   if(x2>x1)
   {
            xvalue=(2*(x1-x2+1));
            motor1(xvalue);
            if(y2>y1)
            {
                     yvalue=(2*(y1-y2+1));
                     motor2(yvalue);

            }
            else if(y2<y1)
            {
                     yvalue=(2*(y1-y2-1));
                     motor2(yvalue);
            }
}
else if(x2<x1)
   {
            xvalue=(2*(x1-x2-1));
            motor1(xvalue);
            if(y2>y1)
            {
                     yvalue=(2*(y1-y2+1));
                     motor2(yvalue);
            }
            else if(y2<y1)
            {
                     yvalue=(2*(y1-y2-1));
                     motor2(yvalue);
            }
}
else
{
            if(y2>y1)
            {
                     yvalue=(2*(y1-y2+1));
                     motor2(yvalue);
            }
            else if(y2<y1)
            {
                     yvalue=(2*(y1-y2-1));
                     motor2(yvalue);
            }
}
motor1(a);
motor2(b);
}
void death(unsigned short x, unsigned short y)
{
board[x][y].empty='1';
move(3,3,x,y);
on(1);
delay_ms(200);
move(x,y,x,8);
delay_ms(200);
on(0);
move(x,8,3,3);
}

unsigned short xassign(char x)
{
  if(x=='A' || x=='a')
    {
     return 0;
    }
    else if(x=='B' || x=='b')
    {
     return 1;
    }
    else if(x=='C' || x=='c')
    {
     return 2;
    }
    else if(x=='D' || x=='d')
    {
     return 3;
    }
    else if(x=='E' || x=='e')
    {
     return 4;
    }
    else if(x=='F' || x=='f')
    {
     return 5;
    }
    else if(x=='G' || x=='g')
    {
     return 6;
    }
    else if(x=='H' || x=='h')
    {
     return 7;
    }
    else
    {
    return 8;
    }
}
unsigned short yassign( char x)
{
 if(x=='0')
    {
     return 0;
    }
    else if(x=='1')
    {
     return 1;
    }
    else if(x=='2')
    {
     return 2;
    }
    else if(x=='3')
    {
     return 3;
    }
    else if(x=='4')
    {
     return 4;
    }
    else if(x=='5')
    {
     return 5;
    }
    else if(x=='6')
    {
     return 6;
    }
    else if(x=='7')
    {
     return 7;
    }
    else
    {
    return 8;
    }

}
unsigned short cheque(unsigned x, unsigned y, short color)
{    int i=0;
     int j=0;
    for(i=0;i<8;i++)
    {
     for(j=0;j<8;j++)
     {
      if(board[i][j].empty==1)
      {
      continue;
      }
      else
      {
      if(board[i][j].color==color)
      {
       if(movechecker(i,j,x,y)>0)
       {
       return 1;//as in check
       }
       else
       {
       return 0;//no check
      }
      }
      else
      {
      continue;
      }
    }
    }
    }
    return 0;
}
unsigned short movechecker(unsigned short ix,unsigned short iy,unsigned short dx,unsigned short dy)
{
      if(board[ix][iy].name=='h')    //horse move
    {
       if(dx==ix+2 && dy==iy+1)
       {
        if(board[dx][dy].empty==1)
        {
        return 1;//move empty box
        }
        else if(board[dx][dy].empty==0 && board[dx][dy].color!=board[ix][iy].color)
        {
        return 2;//kill piece
        }
        else
        {
        return 0;
        }
       }
       else if(dx==ix-2 && dy==iy-1)
       {
        if(board[dx][dy].empty==1)
        {
        return 1;//empty block
        }
        else if(board[dx][dy].empty==0 && board[dx][dy].color!=board[ix][iy].color)
        {
        return 2;//kill piece
        }
        else
        {
        return 0;
        }
       }
       else if(dx==ix+2 && dy==iy-1)
       {
        if(board[dx][dy].empty==1)
        {
        return 1; //empty box
        }
        else if(board[dx][dy].empty==0 && board[dx][dy].color!=board[ix][iy].color)
        {
        return 2;//kill piece
        }
        else
        {
        return 0;
        }
       }
       else if(dx==ix-2 && dy==iy+1)
       {
        if(board[dx][dy].empty==1)
        {
        return 1;//empty box
        }
        else if(board[dx][dy].empty==0 && board[dx][dy].color!=board[ix][iy].color)
        {
        return 2;//kill piece
        }
        else
        {
        return 0;
        }
       }
       else if(dx==ix-1 && dy==iy+2)
       {
        if(board[dx][dy].empty==1)
        {
        return 1;//empty box
        }
        else if(board[dx][dy].empty==0 && board[dx][dy].color!=board[ix][iy].color)
        {
        return 2;//kill piece
        }
        else
        {
        return 0;
        }
       }
       else if(dx==ix+1 && dy==iy+2)
       {
        if(board[dx][dy].empty==1)
        {
        return 1;//empty box
        }
        else if(board[dx][dy].empty==0 && board[dx][dy].color!=board[ix][iy].color)
        {
        return 2;//kill piece
        }
        else
        {
        return 0;
        }
       }
       else if(dx==ix+1 && dy==iy-2)
       {
        if(board[dx][dy].empty==1)
        {
        return 1;//empty box
        }
        else if(board[dx][dy].empty==0 && board[dx][dy].color!=board[ix][iy].color)
        {
        return 2;//kill piece
        }
        else
        {
        return 0;
        }
       }
       else if(dx==ix-1 && dy==iy-2)
       {
        if(board[dx][dy].empty==1)
        {
        return 1;//empty box
        }
        else if(board[dx][dy].empty==0 && board[dx][dy].color!=board[ix][iy].color)
        {
        return 2;//kill piece
        }
        else
        {
        return 0;
        }
       }
       else
       {
       return 0;
       }

    }
    else if(board[ix][iy].name=='r') //rook move
    {
     if(ix==dx || iy==dy)
     {
      if(iy==dy)
      {
       if(ix<dx)
       {
       for(i=ix+1;i<=dx;i++)
       {
        if(board[i][iy].empty==1)
        {
           if(i==dx && iy==dy)
           {
           return 1; //empty can move
           }
        }
        else
        {
        if(board[i][iy].color==board[ix][iy].color)
        {
        return 0;//same color in way
        }
        else if(board[i][iy].color!=board[ix][iy].color)
        {
        if(i==dx && iy==dy)
        {
        return 2;//kill piece
        }
        else
        {
        return 0;//peice in way
        }
        }
        }
        }
        }
        else if(ix>dx)
        {
        for(i=ix-1;i>=dx;i--)
        {
        if(board[i][iy].empty==1)
        {
           if(i==dx && iy==dy)
           {
           return 1;  //empty spot correct move
           }
        }
        else
        {
        if(board[i][iy].color==board[ix][iy].color)
        {
        return 0;//same piece in way incorrect
        }
        else if(board[i][iy].color!=board[ix][iy].color)
        {
        if(i==dx && iy==dy)
        {
        return 2; //kill piece
        }
        else
        {
        return 0;//other color in way
        }
        }
        }
        }
        }
        else
        {
        return 0;
        }
        }

        else if(ix==dx)
        {
        if(iy<dy)
        {
        for(i=iy+1;i<=dy;i++)
        {
        if(board[ix][i].empty==1)
        {
           if(ix==dx && i==dy)
           {
           return 1; //empty correct move
           }
        }
        else
        {
        if(board[ix][i].color==board[ix][iy].color)
        {
        return 0; //same color in way
        }
        else if(board[ix][i].color!=board[ix][iy].color)
        {
        if(ix==dx && i==dy)
        {
        return 2;//kill piece
        }
        else
        {
        return 0; //other color in way
        }
        }
        }
        }
        }
        else if(iy>dy)
        {
        for(i=iy-1;i>=dy;i--)
        {
        if(board[ix][i].empty==1)
        {
           if(ix==dx && i==dy)
           {
           return 1;//empty spot valid
           }
        }
        else
        {
        if(board[ix][i].color==board[ix][iy].color)
        {
        return 0; // same color in the way
        }
        else if(board[ix][i].color!=board[ix][iy].color)
        {
        if(ix==dx && i==dy)
        {
        return 2;//kill piece
        }
        else
        {
        return 0;
        }
        }
        }
        }
        }
        else
        {
        return 0;
        }
        }
        }
        else
        {
        return 0;
        }
        }
    else if(board[ix][iy].name=='p' && board[ix][iy].color==1) //white pawn move
    {
     if(dx>ix)
     {
     if(dx-ix<=2)
      {
      if(dx-ix==2 && dy==iy)//moving 2 spots forward
      {
      if(board[ix][iy].status==0)
      {
       if(board[ix+1][iy].empty==1 && board[ix+2][iy].empty==1)
       {
         board[ix][iy].status=1;
         return 1;//move 2 both empty valid
       }
       else
       {
       return 0; //cant move 2 not empty
       }
      }
      else
      {
      return 0; //has already moved, cant move 2 spots
      }
      }
      if(dx-ix==1 && dy==iy)//moving 1 spot forward
      {
       if(board[ix+1][iy].empty==1)
       {
         board[ix][iy].status=1;
         return 1;//empty box move
       }
       else
       {
       return 0;//not empty return
       }
      }
      if(dx-ix==1 && dy-iy==1) //move right diagonal to kill
      {
           if(board[ix+1][iy+1].empty==0 && board[ix+1][iy+1].color==0)//move to right kill black piece
           {
            board[ix][iy].status=1;
           return 2; //can kill
           }
           else
           {
           return 0;//cannot move
           }
      }
      else if(dx-ix==1 && dy-iy==-1)//move left diagonal to kill
      {
      if(board[ix+1][iy-1].empty==0 && board[ix+1][iy-1].color==0)
           {
            board[ix][iy].status=1;
           return 2;//can kill
           }
           else
           {
           return 0;
           }
      }
     }
     else
     {
     return 0;
     }
     }
     else
     {
     return 0;
     }
    }
    else if(board[ix][iy].name=='p' && board[ix][iy].color==0)//black pawn move
    {
     if(dx<ix)
     {
     if(ix-dx<=2)
     {
      if(dx-ix==-2 && dy==iy)
      {
      if(board[ix][iy].status==0)
      {
       if(board[ix-1][iy].empty==1 && board[ix-2][iy].empty==1) //both blocks empty
       {
         board[ix][iy].status=1;
         return 1;
       }
       else
       {
       return 0;
       }
      }
      else
      {
      return 0;//has already moved
      }
      }
      if(dx-ix==-1 && dy==iy)//move straight and check empty
      {
       if(board[ix-1][iy].empty==1)
       {
         board[ix][iy].status=1;
         return 1;
       }
       else
       {
       return 0;
       }
      }
      if(dx-ix==-1 && dy-iy==1)//move right kill piece
      {
           if(board[ix-1][iy+1].empty==0 && board[ix-1][iy+1].color==1)//kill white piece
           {
           board[ix][iy].status=1;
           return 2; //kill piece
           }
           else
           {
           return 0;
           }
      }
      else if(dx-ix==-1 && dy-iy==-1)//move left kill peice
      {
      if(board[ix-1][iy-1].empty==0 && board[ix-1][iy-1].color==1)//kill white piece
           {
            board[ix][iy].status=1;
           return 2;//kill piece
           }
           else
           {
           return 0;
           }
      }
     }
     else
     {
     return 0;
     }
     }
     else
     {
     return 0;
     }
    }

    else if(board[ix][iy].name=='k') //king move
    {
       if(abs(dx-ix)>1 || abs(dy-iy)>1 || (dx==ix && dy==iy))
       {
        return 0;  //outside parameters
       }
       else
       {
          if(board[dx][dy].empty==1)
          {
          return 1;
          }
          else if(board[dx][dy].empty==0 && board[dx][dy].color!=board[ix][dx].color)
          {
          return 2;
          }
          else
          {
          return 0;
          }
       }
    }
    else if(board[ix][iy].name=='b')  //bishop move
    {
        int x1;
        int y1;
   if(abs(dx-ix)==abs(dy-iy))
   {
            if((ix<dx)&&(iy<dy))
            {
                                for(aa=1;aa<=10;aa++)
                                {    x1=ix+aa;
                                     y1=iy+aa;
                                     if(x1>7 || y1>7)
                                     {
                                     return 0;
                                     }
                                     if(board[x1][y1].empty==1)
                                     {
                                     if(x1==dx && y1==dy)
                                     {
                                     return 1;
                                     }
                                     }
                                     else if(board[x1][y1].empty==0)
                                     {
                                     if(board[x1][y1].color==board[ix][iy].color)
                                     {
                                     return 0;
                                     }
                                     else if(board[x1][y1].color!=board[ix][iy].color)
                                     {
                                     if(dx==x1 && dy==y1)
                                     {
                                     return 2; //kill
                                     }
                                     else
                                     {
                                       return 0;
                                     }
                                     }
                                     }

                        }
               }
                                 
            else if((ix<dx)&&(iy>dy))
            {
                               for(aa=1;aa<=10;aa++)
                                {     x1=ix+aa;
                                      y1=iy-aa;
                                     if(board[x1][y1].empty==1)
                                     {
                                     if(x1==dx && y1==dy)
                                     {
                                     return 1;//can move empty
                                     }
                                     }
                                     else if(board[x1][y1].empty==0)
                                     {
                                     if(board[x1][y1].color==board[ix][iy].color)
                                     {
                                     return 0;
                                     }
                                     else if(board[x1][y1].color!=board[ix][iy].color)
                                     {
                                     if(dx==x1 && dy==y1)
                                     {
                                     return 2; //kill
                                     }
                                     else
                                     {
                                       return 0;
                                     }
                                     }
                                     }


                                     }
             }
           else if((ix>dx)&&(iy<dy))
            {
                                for(aa=1;aa<=10;aa++)
                                {
                                x1=ix-aa;
                                y1=iy+aa;
                                if(y1>7 || y1<0 || x1>7 || x1<0)
                                {
                                return 0;
                                }
                                     if(board[x1][y1].empty==1)
                                     {
                                     if(x1==dx && y1==dy)
                                     {
                                     return 1;
                                     }
                                     }
                                     else if(board[x1][y1].empty==0)
                                     {
                                     if(board[x1][y1].color==board[ix][iy].color)
                                     {
                                     return 0;
                                     }
                                     else if(board[x1][y1].color!=board[ix][iy].color)
                                     {
                                     if(dx==x1 && dy==y1)
                                     {
                                     return 2; //kill
                                     }
                                     else
                                     {
                                       return 0;
                                     }
                                     }
                                     }
                                 }
             }
           else if((ix>dx)&&(iy>dy))
            {
                                for(aa=1;aa<=10;aa++)
                                {     x1=ix-aa;
                                       y1=iy-aa;
                                     if(board[x1][y1].empty==1)
                                     {
                                     if(x1==dx && y1==dy)
                                     {
                                     return 1;
                                     }
                                     }
                                     else if(board[x1][y1].empty==0)
                                     {
                                     if(board[x1][y1].color==board[ix][iy].color)
                                     {
                                     return 0;
                                     }
                                     else if(board[x1][y1].color!=board[ix][iy].color)
                                     {
                                     if(dx==x1 && dy==y1)
                                     {
                                     return 2; //kill
                                     }
                                     else
                                     {
                                       return 0;
                                     }
                                     }
                                     }
                                 }
             }

}
else 
{
        return 0;
}

}
    else if(board[ix][iy].name=='q')   //queen move
        {

        int x1;
        int y1;
   if(abs(dx-ix)==abs(dy-iy))
   {
            if((ix<dx)&&(iy<dy))
            {
                                for(aa=1;aa<=10;aa++)
                                {    x1=ix+aa;
                                     y1=iy+aa;
                                     if(x1>7 || y1>7)
                                     {
                                     return 0;
                                     }
                                     if(board[x1][y1].empty==1)
                                     {
                                     if(x1==dx && y1==dy)
                                     {
                                     return 1;
                                     }
                                     }
                                     else if(board[x1][y1].empty==0)
                                     {
                                     if(board[x1][y1].color==board[ix][iy].color)
                                     {
                                     return 0;
                                     }
                                     else if(board[x1][y1].color!=board[ix][iy].color)
                                     {
                                     if(dx==x1 && dy==y1)
                                     {
                                     return 2; //kill
                                     }
                                     else
                                     {
                                       return 0;
                                     }
                                     }
                                     }

                        }
               }

            else if((ix<dx)&&(iy>dy))
            {
                               for(aa=1;aa<=10;aa++)
                                {     x1=ix+aa;
                                      y1=iy-aa;
                                     if(board[x1][y1].empty==1)
                                     {
                                     if(x1==dx && y1==dy)
                                     {
                                     return 1;//can move empty
                                     }
                                     }
                                     else if(board[x1][y1].empty==0)
                                     {
                                     if(board[x1][y1].color==board[ix][iy].color)
                                     {
                                     return 0;
                                     }
                                     else if(board[x1][y1].color!=board[ix][iy].color)
                                     {
                                     if(dx==x1 && dy==y1)
                                     {
                                     return 2; //kill
                                     }
                                     else
                                     {
                                       return 0;
                                     }
                                     }
                                     }


                                     }
             }
           else if((ix>dx)&&(iy<dy))
            {
                                for(aa=1;aa<=10;aa++)
                                {
                                x1=ix-aa;
                                y1=iy+aa;
                                if(y1>7 || y1<0 || x1>7 || x1<0)
                                {
                                return 0;
                                }
                                     if(board[x1][y1].empty==1)
                                     {
                                     if(x1==dx && y1==dy)
                                     {
                                     return 1;
                                     }
                                     }
                                     else if(board[x1][y1].empty==0)
                                     {
                                     if(board[x1][y1].color==board[ix][iy].color)
                                     {
                                     return 0;
                                     }
                                     else if(board[x1][y1].color!=board[ix][iy].color)
                                     {
                                     if(dx==x1 && dy==y1)
                                     {
                                     return 2; //kill
                                     }
                                     else
                                     {
                                       return 0;
                                     }
                                     }
                                     }
                                 }
             }
           else if((ix>dx)&&(iy>dy))
            {
                                for(aa=1;aa<=10;aa++)
                                {     x1=ix-aa;
                                       y1=iy-aa;
                                     if(board[x1][y1].empty==1)
                                     {
                                     if(x1==dx && y1==dy)
                                     {
                                     return 1;
                                     }
                                     }
                                     else if(board[x1][y1].empty==0)
                                     {
                                     if(board[x1][y1].color==board[ix][iy].color)
                                     {
                                     return 0;
                                     }
                                     else if(board[x1][y1].color!=board[ix][iy].color)
                                     {
                                     if(dx==x1 && dy==y1)
                                     {
                                     return 2; //kill
                                     }
                                     else
                                     {
                                       return 0;
                                     }
                                     }
                                     }
                                 }
             }

}
       else if(ix==dx || iy==dy)
     {
      if(iy==dy)
      {
       if(ix<dx)
       {
       for(i=ix+1;i<=dx;i++)
       {
        if(board[i][iy].empty==1)
        {
           if(i==dx && iy==dy)
           {
           return 1; //empty can move
           }
        }
        else
        {
        if(board[i][iy].color==board[ix][iy].color)
        {
        return 0;//same color in way
        }
        else if(board[i][iy].color!=board[ix][iy].color)
        {
        if(i==dx && iy==dy)
        {
        return 2;//kill piece
        }
        else
        {
        return 0;//peice in way
        }
        }
        }
        }
        }
        else if(ix>dx)
        {
        for(i=ix-1;i>=dx;i--)
        {
        if(board[i][iy].empty==1)
        {
           if(i==dx && iy==dy)
           {
           return 1;  //empty spot correct move
           }
        }
        else
        {
        if(board[i][iy].color==board[ix][iy].color)
        {
        return 0;//same piece in way incorrect
        }
        else if(board[i][iy].color!=board[ix][iy].color)
        {
        if(i==dx && iy==dy)
        {
        return 2; //kill piece
        }
        else
        {
        return 0;//other color in way
        }
        }
        }
        }
        }
        else
        {
        return 0;
        }
        }

        else if(ix==dx)
        {
        if(iy<dy)
        {
        for(i=iy+1;i<=dy;i++)
        {
        if(board[ix][i].empty==1)
        {
           if(ix==dx && i==dy)
           {
           return 1; //empty correct move
           }
        }
        else
        {
        if(board[ix][i].color==board[ix][iy].color)
        {
        return 0; //same color in way
        }
        else if(board[ix][i].color!=board[ix][iy].color)
        {
        if(ix==dx && i==dy)
        {
        return 2;//kill piece
        }
        else
        {
        return 0; //other color in way
        }
        }
        }
        }
        }
        else if(iy>dy)
        {
        for(i=iy-1;i>=dy;i--)
        {
        if(board[ix][i].empty==1)
        {
           if(ix==dx && i==dy)
           {
           return 1;//empty spot valid
           }
        }
        else
        {
        if(board[ix][i].color==board[ix][iy].color)
        {
        return 0; // same color in the way
        }
        else if(board[ix][i].color!=board[ix][iy].color)
        {
        if(ix==dx && i==dy)
        {
        return 2;//kill piece
        }
        else
        {
        return 0;
        }
        }
        }
        }
        }
        else
        {
        return 0;
        }
        }
        }
        else
        {
        return 0;
        }


}


}

unsigned short validity(char x,char y, char x2, char y2, short turn)
{
     unsigned short xx1;
     unsigned short xx2;
     unsigned short yy1=yassign(y);
     unsigned short yy2=yassign(y2);
     xx1=xassign(x);
     xx2=xassign(x2);
     if (xx1==8 || xx2==8)//converts and checks X
     {
         return 0; //out of bounds
     }
     if (yy1==8 || yy2==8)//converts and checks X
     {
         return 0; //out of bounds
     }
     if(board[xx1][yy1].empty==0)
     {
     if(board[xx1][yy1].color==turn)
     {
     if(movechecker(xx1,yy1,xx2,yy2)==1)
     {
     move(3,3,xx1,yy1);
     on(1);
     delay_ms(200);
     move(xx1,yy1,xx2,yy2);
     delay_ms(200);
     on(0);
     move(xx2,yy2,3,3);
     delay_ms(200);
     board[xx2][yy2].empty=board[xx1][yy1].empty;
     board[xx2][yy2].name=board[xx1][yy1].name;
     board[xx2][yy2].status=board[xx1][yy1].status;
     board[xx2][yy2].color=board[xx1][yy1].color;
     board[xx1][yy1].empty=1;
     return 1;
     }
     else if(movechecker(xx1,yy1,xx2,yy2)==2)
     {
     death(xx2,yy2);
     move(3,3,xx1,yy1);
     on(1);
     delay_ms(200);
     move(xx1,yy1,xx2,yy2);
     delay_ms(200);
     on(0);
     move(xx2,yy2,3,3);
     delay_ms(200);
     board[xx2][yy2]=board[xx1][yy1];
     board[xx1][yy1].empty=1;
     return 2;
     }
     else if(movechecker(xx1,yy1,xx2,yy2)==0)
     {
     return 0; //invalid according to stuff
     }
     }
     else
     {
     return 3;
     }
     }
     else
     {
     return 4;//empty
     }


}
char x11='3';
 char x22;
 char y11,y22;
 int x1,x2,y1,y2;
 int jkl=0;
 char nk;
    char output[32];
  short print;
  char txt1[] = "VERY VALID";
char txt2[] = "INVALID";

void main() {
    ANSELB=0;
     TRISB=0;
     ANSELC=0;
     init(); //initializes the board
     ANSELD=0;  ANSELA=0;

      ANSELC=0;
     TRISA=0;
     PORTA=255;
     UART1_Init(9600);                         // initialize UART1 module
     Delay_ms(100);

     Lcd_Init(); // Initialize LCD
     Lcd_Cmd(_LCD_CLEAR); // Clear display
     Lcd_Cmd(_LCD_CURSOR_OFF); // Cursor off

while (1) {
Lcd_Cmd(_LCD_CLEAR);
   while(UART1_Data_Ready()==0);
  if (UART1_Data_Ready() == 1) {          // if data is received
        x11=UART1_Read();
        UART1_Write(x11);
        Lcd_Chr(1, 1, x11);       // sends back text
 }
 while(UART1_Data_Ready()==0);
 if (UART1_Data_Ready() == 1) {          // if data is received
        y11=UART1_Read();
        Lcd_Chr(1, 6, y11);       // sends back text
        //delay_ms(1000);
 }
 while(UART1_Data_Ready()==0);
 if (UART1_Data_Ready() == 1) {          // if data is received
        x22=UART1_Read();
        Lcd_Chr(2, 1, x22);       // sends back text
        //delay_ms(1000);
 }
 while(UART1_Data_Ready()==0);
 if (UART1_Data_Ready() == 1) {          // if data is received
        y22=UART1_Read();
        Lcd_Chr(2, 6, y22);       // sends back text
        //delay_ms(1000);
 }
 Lcd_Cmd(_LCD_CLEAR);
    print=validity(x11,y11,x22,y22,1);
  if(print==0)
  {
    Lcd_Out(1,1,"INVALID");
  }
  else if(print==4)
  {
   Lcd_Out(1,1,"EMPTY");
  }
  else if(print==1)
  {
    Lcd_Out(1,1,"VERY VALID");
  }
  else if(print==3)
  {
    Lcd_Out(1,1,"opponents piece");
  }
  else if(print==2)
  {
      Lcd_Out(1,1,"killed a piece");
  }
  delay_ms(5000);
}

/*ANSELB=0;
     ANSELB=0;
     TRISB=0;
     ANSELC=0;
     TRISC=0;
     init(); //initializes the board
     PORTB=255;
     //motor 2 negative high values
     //motor 1 negative high values
     delay_ms(5000);
   move(3,3,5,5);
   move(5,5,3,3);
     //death(5,5);
      //motor1(4);   */
}