int in1_d2 = 2;
int in2_d3 = 3;
int in3_d4 = 4;
int in4_d5 = 5;

int ir_left = 12;
int ir_middle = 11;
int ir_right = 10;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(in1_d2,OUTPUT);
  pinMode(in2_d3,OUTPUT);
  pinMode(in3_d4,OUTPUT);
  pinMode(in4_d5,OUTPUT);

  pinMode(ir_left,INPUT);
  pinMode(ir_middle,INPUT);
  pinMode(ir_right,INPUT);

  digitalWrite(in1_d2,LOW);
  digitalWrite(in2_d3,LOW);
  digitalWrite(in3_d4,LOW);
  digitalWrite(in4_d5,LOW);
  Serial.println("The line follower is started....");
}

void loop() {
  // put your main code here, to run repeatedly:
  int ir1_state = digitalRead(ir_left);
  int ir2_state = digitalRead(ir_middle);
  int ir3_state = digitalRead(ir_right);
  Serial.print("The ir 1");Serial.println(ir1_state); // low for white detected 0
  Serial.print("The ir 2");Serial.println(ir2_state); // low for white detected 0
  Serial.print("The ir 3");Serial.println(ir3_state); // low for white detected 0

  
  if(ir1_state == HIGH)//WHITE
    if(ir3_state == LOW)//BLUE
    {
        {
          forword();
        }
    }
  if(ir1_state == LOW)//WHITE
    if (ir3_state == LOW)//BLUE
    {
        {
          left();
        }
    }
  if(ir1_state == HIGH)//WHITE
    if (ir3_state == HIGH)//BLUE
    {
        {
          right();
        }
    }
  
  else
  {
    left();
  }
 
}
void forword(void)
{ Serial.println("The moveing forword");
  digitalWrite(in1_d2,HIGH);
  digitalWrite(in2_d3,LOW);
  digitalWrite(in3_d4,HIGH);
  digitalWrite(in4_d5,LOW);
}

void left(void)
{
  Serial.println("The moveing left");
  digitalWrite(in1_d2,LOW);
  digitalWrite(in2_d3,LOW);
  digitalWrite(in3_d4,HIGH);
  digitalWrite(in4_d5,LOW);
}
void right(void)
{
  Serial.println("The moveing right");
  digitalWrite(in1_d2,HIGH);
  digitalWrite(in2_d3,LOW);
  digitalWrite(in3_d4,LOW);
  digitalWrite(in4_d5,LOW);
}
