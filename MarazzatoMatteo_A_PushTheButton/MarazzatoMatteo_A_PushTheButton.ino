//  Copyright ITT Eugenio Barsanti / Produced by MARAZZATO MATTEO - 4BI  //

#include <LiquidCrystal.h>


int btnSX = 8;
int btnCX = 9;
int btnDX = 10;

int lives = 1;
bool select;

int typeOfCharact;
int location;

int startTime;
int finalTime;

//int nmbrOfLivels;
//bool choose;

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);


byte heart[8] = 
{
  B00000,
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000,
};

byte good[8] = 
{
  B00000,
  B00000,
  B01010,
  B00000,
  B10001,
  B01110,
  B00000,
  B00000,
};

byte bad[8] = 
{
  B00000,
  B00000,
  B01010,
  B00000,
  B01110,
  B10001,
  B00000,
  B00000,
};


void setup() 
{
  Serial.begin(9600);
  
  randomSeed(analogRead(5));
  //lives = random(1,6);
  
  bool select = false;
  bool choose = false;
  
  lcd.createChar(0, heart);
  lcd.createChar(1, good);
  lcd.createChar(2, bad);
  
  lcd.begin(16,2);
  
  moveDisplay();

  lcd.clear();

      /*int prova = 0;
      int prova2 = 0;
      Serial.println("PRONTI");
        delay(250);
      while (prova < 500)
      {
        prova2 = digitalRead(btnSX);
        Serial.println(prova);

        if (prova2 == 1)
        {
          prova = 500;
        }

        else {
          prova++;
        }
  }*/

}

void loop() 
{
  lcd.setCursor(0,0);
  lcd.write(byte(0));
  
  while (select == false)
  {
    printStringLives();
    selectLives();
  }

    delay(500);
    
  if (lives >= 1)
  {
    startTime = millis();
    
    for (int i = 1;i<=lives*i;i++)
    {
      printCharacter();
      delay(500);
      //Serial.println(millis()/1000);
    }

    finalTime = millis();
      //delay(200);
  }
  
      delay(500);
    timer();
      delay(4000);

  lcd.clear();
}



void selectLives()
{
  if (digitalRead(btnSX) == HIGH && lives > 1)
  {
    lives--;
    lcd.clear();
    for (int i = 0;i<lives;i++)
    {
      lcd.setCursor(i,0);
      lcd.write(byte(0));
    }
    delay(200);
  }

  else if (digitalRead(btnDX) == HIGH && lives < 6) 
  {
    lives++;
    lcd.clear();
    for (int i = 0;i<lives;i++)
    {
      lcd.setCursor(i,0);
      lcd.write(byte(0));
    }
    delay(200);
  }

  else if (digitalRead(btnCX) == HIGH)
  {
    select = true;
    //startTime = millis();
    lcd.clear();
  }
}

void moveDisplay()
{
  lcd.setCursor(4,0);
  lcd.print("PUSH THE");
  lcd.setCursor(5,1);
  lcd.print("BUTTON");
    delay(1200);
    
  for(int i = 0; i<16; i++)
  {
    lcd.scrollDisplayLeft();
    delay(120);
  }
}

void printStringLives()
{
  lcd.setCursor(10,0);
  lcd.print("SELECT");
  lcd.setCursor(6,1);
  lcd.print("YOUR LIVES");
}

void timer()
{
    //finalTime = millis();
    
    //Serial.println (finalTime/1000);
    //Serial.println (startTime/1000);
    
    lcd.setCursor(2,0);
    lcd.print("PLAYING TIME");

    //Serial.println ((finalTime - startTime)/1000);

    if ((finalTime - startTime)/1000 < 10)
    {
      lcd.setCursor(4,1);
      lcd.print("00");
      lcd.setCursor(6,1);
      lcd.print((finalTime - startTime)/1000);
      lcd.setCursor(7,1);
      lcd.print(" sec");
    }

    else if ((finalTime - startTime)/1000 >= 10 && ((finalTime - startTime)/1000) < 100)
    {
      lcd.setCursor(4,1);
      lcd.print("0");
      lcd.setCursor(5,1);
      lcd.print((finalTime - startTime)/1000);
      lcd.setCursor(7,1);
      lcd.print(" sec");
    }

    else if ((finalTime - startTime)/1000 >= 100)
    {
      lcd.setCursor(4,1);
      lcd.print((finalTime - startTime)/1000);
      lcd.setCursor(7,1);
      lcd.print(" sec");
    }

    lives = 1;
    select = false;
}

void printCharacter()
{
  typeOfCharact = random(0,9);
  location = random(1,4);

  if (location == 1)
  {
    if (typeOfCharact < 8)
    {
      lcd.clear();
      lcd.setCursor(3,1);
      lcd.write(byte(1));
      redrawLives();

        delay(500);
      
      int wait = 0;
      int pressure = 0;
      while (wait < 300)
      {
        pressure = digitalRead(btnSX);
        if (pressure == 1)
        {
          wait = 300;
        }

        else {wait++;}
      }
      
        delay(100);

      if (pressure == 1)
      {
        lives--;
        redrawLives();
      }

      else
      {
        redrawLives();
      }
    }

    else if (typeOfCharact >= 8)
    {
      lcd.clear();
      lcd.setCursor(3,1);
      lcd.write(byte(2));
      redrawLives();

        delay(500);
      
      int wait = 0;
      int pressure = 0;
      while (wait < 300)
      {
        pressure = digitalRead(btnSX);
        if (pressure == 1)
        {
          wait = 300;
        }

        else {wait++;}
      }
      
        delay(100);

      if (pressure == 1)
      {
        redrawLives();
      }

      else
      {
        lives--;
        redrawLives();
      }
    }
    
  }

  else if (location == 2)
  {
    if (typeOfCharact < 8)
    {
      lcd.clear();
      lcd.setCursor(8,1);
      lcd.write(byte(1));
      redrawLives();

        delay(500);
      
      int wait = 0;
      int pressure = 0;
      while (wait < 300)
      {
        pressure = digitalRead(btnCX);
        if (pressure == 1)
        {
          wait = 300;
        }

        else {wait++;}
      }
      
        delay(100);

      if (pressure == 1)
      {
        lives--;
        redrawLives();
      }

      else
      {
        redrawLives();
      }
    }

    else if (typeOfCharact >= 8)
    {
      lcd.clear();
      lcd.setCursor(8,1);
      lcd.write(byte(2));
      redrawLives();

        delay(500);
      
      int wait = 0;
      int pressure = 0;
      while (wait < 300)
      {
        pressure = digitalRead(btnCX);
        if (pressure == 1)
        {
          wait = 300;
        }

        else {wait++;}
      }
      
        delay(100);

      if (pressure == 1)
      {
        redrawLives();
      }

      else
      {
        lives--;
        redrawLives();
      }
    }
  }

  else if (location == 3)
  {
    if (typeOfCharact < 8)
    {
      lcd.clear();
      lcd.setCursor(12,1);
      lcd.write(byte(1));
      redrawLives();

        delay(500);
      
      int wait = 0;
      int pressure = 0;
      while (wait < 300)
      {
        pressure = digitalRead(btnDX);
        if (pressure == 1)
        {
          wait = 300;
        }

        else {wait++;}
      }
      
        delay(100);

      if (pressure == 1)
      {
        lives--;
        redrawLives();
      }

      else
      {
        redrawLives();
      }
    }

    else if (typeOfCharact >= 8)
    {
      lcd.clear();
      lcd.setCursor(12,1);
      lcd.write(byte(2));
      redrawLives();

        delay(500);
      
      int wait = 0;
      int pressure = 0;
      while (wait < 300)
      {
        pressure = digitalRead(btnDX);
        if (pressure == 1)
        {
          wait = 300;
        }

        else {wait++;}
      }
      
        delay(100);

      if (pressure == 1)
      {
        redrawLives();
      }

      else
      {
        lives--;
        redrawLives();
      }
    }
  }
  
}

void redrawLives()
{

  if (lives == 0){delay(250);lcd.clear();}

  else
  {
    for (int i = 0;i<lives;i++)
    {
      lcd.setCursor(i,0);
      lcd.write(byte(0));
    }
  }
}

void printLevels()
{
  lcd.setCursor(0,0);
  lcd.print("EASY");
  lcd.setCursor(5,1);
  lcd.print("MEDIUM");
  lcd.setCursor(12,0);
  lcd.print("HARD");
}





















//  Copyright ITT Eugenio Barsanti / Produced by MARAZZATO MATTEO - 4BI  //
