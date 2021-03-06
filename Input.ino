boolean leftButtonState = false; // The left button state
boolean leftPrevButtonState = true; // The left button's previous state (true to prevent program from thinking button was pushed at beginning)
boolean filteredLeft = false;

boolean rightButtonState = false; // The right button state
boolean rightPrevButtonState = true; // The right button's previous state (true to prevent program from thinking button was pushed at beginning)
boolean filteredRight = false;

// Updates the input variables based on pin state
void updateInput()
{
  int inputLeft = analogRead(buttonPinLeft);
  int inputRight = analogRead(buttonPinRight);

  leftButtonState = (inputLeft > 511);
  rightButtonState = (inputRight > 511);

  if (leftButtonState && !leftPrevButtonState)
  {
    filteredLeft = true;
  }
  if (rightButtonState && !rightPrevButtonState)
  {
    filteredRight = true;
  }

  /*
    Serial.print("(");
    Serial.print(inputLeft);
    Serial.print(", ");
    Serial.print(inputRight);
    Serial.println(")");
  */

  // Sets the previous button states for the next time input() is called
  leftPrevButtonState = leftButtonState;
  rightPrevButtonState = rightButtonState;
}

// Returns if the left button is pressed (one time use to prevent button spamming)
boolean isLeftButton()
{
  boolean toReturn = filteredLeft;
  filteredLeft = false;
  return toReturn; // If the button was just pressed then set the filter to true
}

// Returns if the right button is pressed (one time use to prevent button spamming)
boolean isRightButton()
{
  boolean toReturn = filteredRight;
  filteredRight = false;
  return toReturn; // If the button was just pressed then set the filter to true
}

// Returns if the left button is pressed
boolean isLeftButtonUnfil()
{
  return leftButtonState;
}

// Returns if the right button is pressed
boolean isRightButtonUnfil()
{
  return rightButtonState;
}
