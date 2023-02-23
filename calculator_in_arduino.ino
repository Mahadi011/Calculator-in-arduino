#include <Keypad.h>
#define ROW 4
#define COL 4

char keys[ROW][COL]=
{
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'c','0','=','/'}
};

byte rowPins[ROW]= {9,8,7,6};
byte colPins[COL]= {5,4,3,2};


Keypad myKeypad = Keypad(makeKeymap(keys), rowPins,colPins,ROW,COL);


boolean pValue = false;
boolean next = false;
boolean final = false;
String num1,num2;
int answer;
char op;

void setup(){
  Serial.begin(9600);
  
}

void loop()
{
  char key = myKeypad.getKey();
  if(key!= NO_KEY && (key=='1'||key=='2'||key=='3'||key=='4'||key=='5'||key=='6'||key=='7'||key=='8'||key=='9'||key=='0'))
  {
    if(pValue==false)
    {
      num1=num1+key;
      Serial.print(key);
    }
    else
    {
      num2=num2+key;
      Serial.print(key);
      final= true;
    }
    
    
  }
  else if(pValue==false && key!=NO_KEY && (key=='+'||key=='-'||key=='*'||key=='/'))
  {
    pValue=true;
    op=key;
    Serial.print(op);
  }
  else if(final == true && key!= NO_KEY && key =='=')
          {
            Serial.print(key);
            pValue=false;
            if(op=='+')
            {
              answer= num1.toInt()+num2.toInt();
              Serial.println(answer);
            }
            else if(op=='-')
            {
              answer= num1.toInt()-num2.toInt();
              Serial.println(answer);
            }
            else if(op=='*')
            {
              answer= num1.toInt()* num2.toInt();
              Serial.println(answer);
            }
            else
            {
              answer= num1.toInt()/num2.toInt();
              Serial.println(answer);
            }
        final=false;
            num1="";
            num2="";
            answer=0;
          }
  else if(key!= NO_KEY && key=='c')
  {
    pValue=false;
    final=false;
    num1="";
    num2="";
    answer=0;
    op = '\0';
    Serial.println("deleted");
  }
  

 
  
}
