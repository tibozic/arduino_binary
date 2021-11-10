#define NUM_OF_BITS 4

int values[NUM_OF_BITS];
int pins[NUM_OF_BITS] = {2, 3, 4, 5};

void binary(int array[], int length);
void clear_array(int array[], int length);
void display_array(int pins[], int values[], int length);

void setup() {
  /*
   * This programs calculates the binary values of numbers to 16, then
   * displays them using LED lights.
  */
  pinMode(LED_BUILTIN, OUTPUT);
  for (int i = 0; i < NUM_OF_BITS; i++)
  {
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  for (int j = 0; j < 16; j++)
  {
    binary(j, values, NUM_OF_BITS);
    display_array(pins, values, NUM_OF_BITS);
    delay(1000);
  }
  clear_array(values, NUM_OF_BITS);
}

void binary(int number, int array[], int length)
{
  /*
   * Calculates the binary value of input number and stores it in the array
   * with the first bit of array being the MSB (most significant bit)
  */
  if (number > 15)
  {
    exit(1);
  }
  int res = number; // res is result of divison
  int rem; // rem is remainder of divison
  int counter = length-1;

  while (res > 0)
  {
    rem = res % 2;
    res = res / 2;
    array[counter] = rem;
    counter--;
  }
}

void clear_array(int array[], int length)
{
  /*
   * Sets all the values in the array to 0
   * Turns the builtin led while doing so
  */
  digitalWrite(LED_BUILTIN, 1);
  for (int i = 0; i < length; i++)
  {
    array[i] = 0;
  }
  delay(1000);
  digitalWrite(LED_BUILTIN, 0);
}

void display_array(int pins[], int values[], int length)
{
  /*
   * Loops through all the pins and sets them to their appropriate values
  */
  for (int i = 0; i < length; i++)
  {
    digitalWrite(pins[i], values[i]);
  }
}
