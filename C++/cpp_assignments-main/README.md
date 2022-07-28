## Description
Write an utility application which can read a file based on the mapping provided as below and generate the output based on given format. The application should take a file and type of output as input argument.

Input record format [fixed length] :-
```
{
    lastName       {15 bytes}
    firstName      {15 bytes}
    middleName     {10 bytes}
    AKA(nickName)  {5 bytes}
    houseNo        {20 bytes}
    streetAddress  {15 bytes}
    City           {15 bytes}
    State          {15 bytes}
    Zip            {6 bytes}
}
```

Example:- Content of file may look like below,
```
lastName  firstName  middleName  nickName  houseNo  streetAddress   City   State   Zip
patel      manish    s           t         2103     swargate        Pune   MH     411021
Ltd        data      Axle        dax       8        sb road         Pune   MH     411008
```
Input file will have the data in above given format. Where string type fields will have empty byte's filled with whitespaces. But our application should trim any leading/trailing whitespaces before generating the conversion output.

## Output format
 Process the input file and build out into three fields and those field can be written based on given output type format.
 ```
 name        {firstName lastName}
 address1    {houseNo streetAddress}
 address2    {City, State Zip}
 ```

  1. Envelope format (each record is put into 3 lines as )
  ```
     "name       (record1)
      address1   (record1)
      address2   (record1)"
  ```
  ```
     Sample output
     myFname myLname,
     houseNo myStreet,
     myCity, myState myZip
  ```
  ```
     eg. manish patel,
         2103 swargate,
         Pune, MH 411021
  ```
  2. Fixed format (each output record into one line)
  ```
     "name address1 address2"
  ```
  ```
     Sample Output
     myFname myLname      houseNo myStreet      myCity, myState myZip
  ```
  ```
     eg. name = "manish patel                   "
      (Here actual length of name is 12 bytes so after that we should have remaining bytes as whitespaces)
  ```
  3. Fixed format with CSV (each output record into one line)
  ```
    "name,address1,address2"
  ```
  ```
     Sample Output
     "myFname myLname","houseNo myStreet","myCity, myState myZip"
  ```
  ```
     eg. "manish patel","2103 swargate","Pune, MH 411021"
  ```

## Command line Usage
  The c++ conversion application should take few command line arguments to process the input. below is the list of options, [* mandatory arguments]

   1. input_file (*)
     - Give path/filename to refer input files

   2. output_format (*)
     - {envelope, fixed_length, csv}

   3. nick_name
     - If nick_name option provided then firstName will be replace by nickName in process records.
  ```
      eg. name={nickName lastName}
  ```

   4. matchcode
     - If matchcode option provided then add keylookup field at start of the each record for fixed format.
  ```
      matchcode
         length = 8byte
         1 byte = first alphabate from streetaddress
         2 byte = first alphabate from firstName
         3-8 byte = Zip code
          eg. (for 1st record)     "sm411021"
  ```

   5. uppercase
     - If Uppercase option provided then all output should be in below format,
  ```
      eg. "dataaxle" => "DATAAXLE"
  ```

   6. titlecase
     - If Titlecase option provided then all output should be in below format,
 ```
      eg. "dataaxle" => "Dataaxle"
 ```
 
#### NOTE:  if uppercase and titlecase both arguments passed then consider the first and ignore second.

## The application can be run by passing arguments as below,
  ```
 ./conv_application --input_file ifile.in --output_format envelope --nick_name --matchcode --uppercase --titlecase
  ```
## Note :- Make use of below in your implementation,
  *	getopt_long for command line parsing
  *	Add --verbose flag for the logs
  *	C++ classes & other oops concepts
  *	STL libraries
  *	Build system - Cmake or Makefile

