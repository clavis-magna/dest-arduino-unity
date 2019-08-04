// create a variable called last_time 
// it can hold a very large number (long)
// but only positive numbers (unsigned)
// assinged it a value of 0
unsigned long last_time = 0;

// creat a variable called count
// it is an 'int' or integer
// assinged it a value of 0
int count = 0;

// setup happens once when the arduino recieves power 
// or when it is reset
void setup()
{
    // setup serial messaging 
    // 9600 is the BAUD rate.
    // or how fast the info is transfered (just keep it at 9600)
    Serial.begin(9600);
}

// loop happens over and over again as fast as it can
// it is a lot like the 'draw' loop in processing or p5.js
void loop()
{
    // millis() is how much time in milliseconds
    // have passed since we started the arduino running
    // we are basically checking if 10 milliseconds have passed 
    // and then doing some stuff 
    // (eventually this stuff will be to read a sensor and send its value to unity)
    // the stuff is what is inside the curly {} brackets
    if (millis() > last_time + 10)
    {
        // here we are sending (using Serial.print) our first piece of data
        // over serial - the string 'cat~'
        Serial.print("cat~");
        // then we send the value of count
        // Serial.println is short for 'print line'
        Serial.println(String(count));

        // we send our second piece of data
        Serial.print("elephant~");
        Serial.println(String(count));

        // add 1 to the value of the count variable
        count = count + 1;
        // reset the value of last_time to the current time from millis()
        last_time = millis();
    }

    // Send some message when I receive an 'A' or a 'Z'.
    // we are not currently interested in recieving messages
    // we will use this at a later stage
    // note the multi-line comment that comments out this whole code block
    /*
    switch (Serial.read())
    {
        case 'A':
            Serial.println("That's the first letter of the abecedarium.");
            break;
        case 'Z':
            Serial.println("That's the last letter of the abecedarium.");
            break;
    }
    */
}
