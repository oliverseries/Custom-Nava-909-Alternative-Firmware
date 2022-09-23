int flamMenuSelection = 0;

void stepBtnProbMenu() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Probability");
  lcd.setCursor(0, 1);
  lcd.print(String(10-pattern[ptrnBuffer].stepProb[curInst][FirstBitOn()]));
  LcdUpdate();
}

void stepBtnFlamMenu() {
  lcd.clear();
  lcd.setCursor(0, 0);
  if (flamMenuSelection == 0) {
    lcd.print("Prob.    repeats");
  } else if (flamMenuSelection == 1) {
    lcd.print("prob.    Repeats");
  }
  lcd.setCursor(0, 1);
  lcd.print(String(10-pattern[ptrnBuffer].stepProb[curInst][FirstBitOn()]));
  lcd.setCursor(9, 1);
  lcd.print(String(1+pattern[ptrnBuffer].stepFlamRpts[FirstBitOn()]));
  LcdUpdate();
}

void stepBtnMenuEncoderHandler() {
  if (!curFlam) {
    // A has gone from high to low
    if (encoder_B) {
      // B is high so clockwise
      if (pattern[ptrnBuffer].stepProb[curInst][FirstBitOn()] > 0) {
        pattern[ptrnBuffer].stepProb[curInst][FirstBitOn()] -= 1;
      }
    } else {
      if (pattern[ptrnBuffer].stepProb[curInst][FirstBitOn()] < 10) {
        pattern[ptrnBuffer].stepProb[curInst][FirstBitOn()] += 1;
      }
    }
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Probability");
    lcd.setCursor(0, 1);
    lcd.print(String(10-pattern[ptrnBuffer].stepProb[curInst][FirstBitOn()]));
    LcdUpdate();
  } else if (curFlam) {
    // A has gone from high to low
    if (encoder_B) {
      // B is high so clockwise
      if (flamMenuSelection == 0 && pattern[ptrnBuffer].stepProb[curInst][FirstBitOn()] > 0) {
        pattern[ptrnBuffer].stepProb[curInst][FirstBitOn()] -= 1;
      } else if (flamMenuSelection == 1 && pattern[ptrnBuffer].stepFlamRpts[FirstBitOn()] < 24) {
        pattern[ptrnBuffer].stepFlamRpts[FirstBitOn()] += 1;
      }
      lcd.clear();
      lcd.setCursor(0, 0);
      if (flamMenuSelection == 0) {
        lcd.print("Prob.    repeats");
      } else if (flamMenuSelection == 1) {
        lcd.print("prob.    Repeats");
      }
    } else {
      if (flamMenuSelection == 0 && pattern[ptrnBuffer].stepProb[curInst][FirstBitOn()] < 10) {
        pattern[ptrnBuffer].stepProb[curInst][FirstBitOn()] += 1;
      } else if (flamMenuSelection == 1 && pattern[ptrnBuffer].stepFlamRpts[FirstBitOn()] > 0) {
        pattern[ptrnBuffer].stepFlamRpts[FirstBitOn()] -= 1;
      }
      lcd.clear();
      lcd.setCursor(0, 0);
      if (flamMenuSelection == 0) {
        lcd.print("Prob.    repeats");
      } else if (flamMenuSelection == 1) {
        lcd.print("prob.    Repeats");
      }
    }
    lcd.setCursor(0, 1);
    lcd.print(String(10-pattern[ptrnBuffer].stepProb[curInst][FirstBitOn()]));
    lcd.setCursor(9, 1);
    lcd.print(String(1+pattern[ptrnBuffer].stepFlamRpts[FirstBitOn()]));
    LcdUpdate();
  }
}

void encoderPressFlamMenu() {
  if (flamMenuSelection == 0) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("prob.    Repeats");
    flamMenuSelection = 1;
  } else if (flamMenuSelection == 1) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Prob.    repeats");
    flamMenuSelection = 0;
  }
  lcd.setCursor(0, 1);
  lcd.print(String(10-pattern[ptrnBuffer].stepProb[curInst][FirstBitOn()]));
  lcd.setCursor(9, 1);
  lcd.print(String(1+pattern[ptrnBuffer].stepFlamRpts[FirstBitOn()]));
  LcdUpdate();
}