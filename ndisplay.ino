#include "ndisplay.h"

#define p2 1
#define p3 2
#define p4 42
#define p5 41
#define p8 40
#define p9 39

void a_1(){
	pinMode(p2, OUTPUT);
  pinMode(p3, OUTPUT);
  pinMode(p4, INPUT);
	pinMode(p5, INPUT);
  pinMode(p8, INPUT);
  pinMode(p9, INPUT);

  digitalWrite(p2, HIGH);
  digitalWrite(p3, LOW);
}
void b_1(){
	pinMode(p2, OUTPUT);
  pinMode(p3, OUTPUT);
  pinMode(p4, INPUT);
	pinMode(p5, INPUT);
  pinMode(p8, INPUT);
  pinMode(p9, INPUT);

  digitalWrite(p3, HIGH);
  digitalWrite(p2, LOW);
}
void c_1(){
	pinMode(p2, INPUT);
    pinMode(p3, OUTPUT);
    pinMode(p4, OUTPUT);
	pinMode(p5, INPUT);
    pinMode(p8, INPUT);
    pinMode(p9, INPUT);

    digitalWrite(p3, HIGH);
    digitalWrite(p4, LOW);
}
void d_1(){
	pinMode(p2, OUTPUT);
    pinMode(p3, INPUT);
    pinMode(p4, OUTPUT);
	pinMode(p5, INPUT);
    pinMode(p8, INPUT);
    pinMode(p9, INPUT);

    digitalWrite(p2, HIGH);
    digitalWrite(p4, LOW);
}
void e_1(){
	pinMode(p2, OUTPUT);
  pinMode(p3, INPUT);
  pinMode(p4, INPUT);
	pinMode(p5, OUTPUT);
  pinMode(p8, INPUT);
  pinMode(p9, INPUT);

  digitalWrite(p2, HIGH);
  digitalWrite(p5, LOW);
}
void f_1(){
	pinMode(p2, OUTPUT);
    pinMode(p3, INPUT);
    pinMode(p4, INPUT);
	pinMode(p5, INPUT);
    pinMode(p8, OUTPUT);
    pinMode(p9, INPUT);

    digitalWrite(p2, HIGH);
    digitalWrite(p8, LOW);
}
void g_1(){
	pinMode(p2, OUTPUT);
    pinMode(p3, INPUT);
    pinMode(p4, INPUT);
	pinMode(p5, INPUT);
    pinMode(p8, INPUT);
    pinMode(p9, OUTPUT);

    digitalWrite(p2, HIGH);
    digitalWrite(p9, LOW);
}

void a_2(){
	pinMode(p2, OUTPUT);
    pinMode(p3, INPUT);
    pinMode(p4, OUTPUT);
	pinMode(p5, INPUT);
    pinMode(p8, INPUT);
    pinMode(p9, INPUT);

    digitalWrite(p4, HIGH);
    digitalWrite(p2, LOW);
}
void b_2(){
	pinMode(p2, INPUT);
    pinMode(p3, OUTPUT);
    pinMode(p4, OUTPUT);
	pinMode(p5, INPUT);
    pinMode(p8, INPUT);
    pinMode(p9, INPUT);

    digitalWrite(p4, HIGH);
    digitalWrite(p3, LOW);
}
void c_2(){
	pinMode(p2, INPUT);
    pinMode(p3, INPUT);
    pinMode(p4, OUTPUT);
	pinMode(p5, OUTPUT);
    pinMode(p8, INPUT);
    pinMode(p9, INPUT);

    digitalWrite(p4, HIGH);
    digitalWrite(p5, LOW);
}
void d_2(){
	pinMode(p2, INPUT);
    pinMode(p3, INPUT);
    pinMode(p4, OUTPUT);
	pinMode(p5, INPUT);
    pinMode(p8, OUTPUT);
    pinMode(p9, INPUT);

    digitalWrite(p4, HIGH);
    digitalWrite(p8, LOW);
}
void e_2(){
	pinMode(p2, INPUT);
    pinMode(p3, OUTPUT);
    pinMode(p4, INPUT);
	pinMode(p5, INPUT);
    pinMode(p8, OUTPUT);
    pinMode(p9, INPUT);

    digitalWrite(p3, HIGH);
    digitalWrite(p8, LOW);
}
void f_2(){
	pinMode(p2, INPUT);
    pinMode(p3, OUTPUT);
    pinMode(p4, INPUT);
	pinMode(p5, INPUT);
    pinMode(p8, INPUT);
    pinMode(p9, OUTPUT);

    digitalWrite(p3, HIGH);
    digitalWrite(p9, LOW);
}
void g_2(){
	pinMode(p2, INPUT);
    pinMode(p3, INPUT);
    pinMode(p4, OUTPUT);
	pinMode(p5, INPUT);
    pinMode(p8, INPUT);
    pinMode(p9, OUTPUT);

    digitalWrite(p4, HIGH);
    digitalWrite(p9, LOW);
}

void a_3(){
	pinMode(p2, INPUT);
    pinMode(p3, OUTPUT);
    pinMode(p4, INPUT);
	pinMode(p5, OUTPUT);
    pinMode(p8, INPUT);
    pinMode(p9, INPUT);

    digitalWrite(p5, HIGH);
    digitalWrite(p3, LOW);
}
void b_3(){
	pinMode(p2, INPUT);
    pinMode(p3, OUTPUT);
    pinMode(p4, INPUT);
	pinMode(p5, INPUT);
    pinMode(p8, OUTPUT);
    pinMode(p9, INPUT);

    digitalWrite(p8, HIGH);
    digitalWrite(p3, LOW);
}
void c_3(){
	pinMode(p2, INPUT);
    pinMode(p3, INPUT);
    pinMode(p4, OUTPUT);
	pinMode(p5, INPUT);
    pinMode(p8, OUTPUT);
    pinMode(p9, INPUT);

    digitalWrite(p8, HIGH);
    digitalWrite(p4, LOW);
}
void d_3(){
	pinMode(p2, INPUT);
    pinMode(p3, INPUT);
    pinMode(p4, OUTPUT);
	pinMode(p5, OUTPUT);
    pinMode(p8, INPUT);
    pinMode(p9, INPUT);

    digitalWrite(p5, HIGH);
    digitalWrite(p4, LOW);
}
void e_3(){
	pinMode(p2, INPUT);
    pinMode(p3, INPUT);
    pinMode(p4, INPUT);
	pinMode(p5, OUTPUT);
    pinMode(p8, OUTPUT);
    pinMode(p9, INPUT);

    digitalWrite(p5, HIGH);
    digitalWrite(p8, LOW);
}
void f_3(){
	pinMode(p2, INPUT);
    pinMode(p3, INPUT);
    pinMode(p4, INPUT);
	pinMode(p5, OUTPUT);
    pinMode(p8, INPUT);
    pinMode(p9, OUTPUT);

    digitalWrite(p5, HIGH);
    digitalWrite(p9, LOW);
}
void g_3(){
	pinMode(p2, OUTPUT);
    pinMode(p3, INPUT);
    pinMode(p4, INPUT);
	pinMode(p5, INPUT);
    pinMode(p8, OUTPUT);
    pinMode(p9, INPUT);

    digitalWrite(p8, HIGH);
    digitalWrite(p2, LOW);
}

void dot_1(){
	pinMode(p2, INPUT);
    pinMode(p3, OUTPUT);
    pinMode(p4, INPUT);
	pinMode(p5, OUTPUT);
    pinMode(p8, INPUT);
    pinMode(p9, INPUT);

    digitalWrite(p3, HIGH);
    digitalWrite(p5, LOW);
    delay(1);
    off();
}
void dot_2(){
	pinMode(p2, OUTPUT);
    pinMode(p3, INPUT);
    pinMode(4, INPUT);
	pinMode(p5, OUTPUT);
    pinMode(p8, INPUT);
    pinMode(p9, INPUT);

    digitalWrite(p5, HIGH);
    digitalWrite(p2, LOW);
}
void dot_3(){
	pinMode(p2, INPUT);
    pinMode(p3, INPUT);
    pinMode(p4, INPUT);
	pinMode(p5, OUTPUT);
    pinMode(p8, OUTPUT);
    pinMode(p9, INPUT);

    digitalWrite(p8, HIGH);
    digitalWrite(p5, LOW);
}
void off() {
    pinMode(p2, INPUT);
    pinMode(p3, INPUT);
    pinMode(p4, INPUT);
    pinMode(p5, INPUT);
    pinMode(p8, INPUT);
    pinMode(p9, INPUT);
}
void firstDigit() {
    a_1();
    delay(1);      
    b_1();
    delay(1);
    c_1();
    delay(1);
    d_1();
    delay(1);
    e_1();
    delay(1);
    f_1();
    delay(1);
    off();     
}
void secondDigit(int y) {
   if(y == 0) {
      a_2();
      delay(1);      
      b_2();
      delay(1);
      c_2();
      delay(1);
      d_2();
      delay(1);
      e_2();
      delay(1);
      f_2();
      delay(1);
      off();     
   }
    else if (y==1) {
        b_2();
        delay(1);
        c_2();
        delay(1);
        off();
    }
    else if (y==2) {    
        a_2();
        delay(1);
        b_2();
        delay(1);
        g_2();
        delay(1);
        e_2();
        delay(1);
        d_2();
        delay(1);  
        off();
    }
    else if (y==3) { 
        a_2();
        delay(1);
        d_2();
        delay(1);
        b_2();
        delay(1);
        c_2();
        delay(1);
        g_2();
        delay(1);   
        off();
    }
    else if (y==4) { 
        b_2();
        delay(1);
        c_2();
        delay(1);
        f_2();
        delay(1);
        g_2();
        delay(1);  
        off();  
    }
    else if (y==5) { 
        a_2();
        delay(1);
        f_2();
        delay(1);
        g_2();
        delay(1);
        c_2();
        delay(1);
        d_2();
        delay(1); 
        off(); 
    }
    else if (y==6) { 
        a_2();
        delay(1);
        f_2();
        delay(1);
        g_2();
        delay(1);
        c_2();
        delay(1);
        d_2();
        delay(1);
        e_2();
        delay(1); 
        off();                         
    }
    else if (y==7) {
        a_2();
        delay(1); 
        b_2();
        delay(1);
        c_2();
        delay(1);
        off();
    }
    else if (y==8) {
        a_2();
        delay(1);
        b_2();
        delay(1);
        c_2();
        delay(1);
        d_2();
        delay(1);
        e_2();
        delay(1);
        f_2();
        delay(1);
        g_2();
        delay(1); 
        off();     
    } 
    else if (y==9) {
        a_2();
        delay(1);
        b_2();
        delay(1);
        c_2();
        delay(1);
        d_2();
        delay(1);
        f_2();
        delay(1);
        g_2();
        delay(1);
        off();
    }
}
void thridDigit(int z) {
   if(z == 0) {
      a_3();
      delay(1);      
      b_3();
      delay(1);
      c_3();
      delay(1);
      d_3();
      delay(1);
      e_3();
      delay(1);
      f_3();
      delay(1);
      off();     
   }
    else if (z==1) {
        b_3();
        delay(1);
        c_3();
        delay(1);
        off();
    }
    else if (z==2) {    
        a_3();
        delay(1);
        b_3();
        delay(1);
        g_3();
        delay(1);
        e_3();
        delay(1);
        d_3();
        delay(1);  
        off();
    }
    else if (z==3) { 
        a_3();
        delay(1);
        d_3();
        delay(1);
        b_3();
        delay(1);
        c_3();
        delay(1);
        g_3();
        delay(1);   
        off();
    }
    else if (z==4) { 
        b_3();
        delay(1);
        c_3();
        delay(1);
        f_3();
        delay(1);
        g_3();
        delay(1);  
        off();  
    }
    else if (z==5) { 
        a_3();
        delay(1);
        f_3();
        delay(1);
        g_3();
        delay(1);
        c_3();
        delay(1);
        d_3();
        delay(1); 
        off(); 
    }
    else if (z==6) { 
        a_3();
        delay(1);
        f_3();
        delay(1);
        g_3();
        delay(1);
        c_3();
        delay(1);
        d_3();
        delay(1);
        e_3();
        delay(1); 
        off();                         
    }
    else if (z==7) {
        a_3();
        delay(1); 
        b_3();
        delay(1);
        c_3();
        delay(1);
        off();
    }
    else if (z==8) {
        a_3();
        delay(1);
        b_3();
        delay(1);
        c_3();
        delay(1);
        d_3();
        delay(1);
        e_3();
        delay(1);
        f_3();
        delay(1);
        g_3();
        delay(1); 
        off();     
    } 
    else if (z==9) {
        a_3();
        delay(1);
        b_3();
        delay(1);
        c_3();
        delay(1);
        d_3();
        delay(1);
        f_3();
        delay(1);
        g_3();
        delay(1);
        off();
    }
}
