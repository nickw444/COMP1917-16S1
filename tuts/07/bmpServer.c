/*
 *  bmpServer.c
 *  1917 serve that 3x3 bmp from lab3 Image activity
 *
 *  Created by Tim Lambert on 02/04/12.
 *  Containing code created by Richard Buckland on 28/01/11.
 *  Copyright 2012 Licensed under Creative Commons SA-BY-NC 3.0. 
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <math.h>

int waitForConnection (int serverSocket);
int makeServerSocket (int portno);
void serveBMP (int socket);

#define BYTES_PER_PIXEL 3
#define BITS_PER_PIXEL (BYTES_PER_PIXEL*8)
#define NUMBER_PLANES 1
#define PIX_PER_METRE 2835
#define MAGIC_NUMBER 0x4d42
#define NO_COMPRESSION 0
#define OFFSET 54
#define DIB_HEADER_SIZE 40
#define NUM_COLORS 0

#define TRUE 1
#define FALSE 0

#define NORM_PIX_SIZE 0.0078125
#define ESCAPE_VAL 255
 
#define SIZE 512
#define BMP_FILE "chess.bmp"

#define SIMPLE_SERVER_VERSION 1.0
#define REQUEST_BUFFER_SIZE 1000
#define DEFAULT_PORT 1917
#define NUMBER_OF_PAGES_TO_SERVE 10

typedef unsigned char  bits8;
typedef unsigned short bits16;
typedef unsigned int   bits32;
 
void createbmp ();
void writeHeader (FILE *file);
int escapeSteps(double Re, double Im);
double displacement(double Real, double Img);


int main (int argc, char *argv[]) {
      
   printf ("************************************\n");
   printf ("Starting simple server %f\n", SIMPLE_SERVER_VERSION);
   printf ("Serving bmps since 2012\n");   
   
   int serverSocket = makeServerSocket (DEFAULT_PORT);   
   printf ("Access this server at http://localhost:%d/\n", DEFAULT_PORT);
   printf ("************************************\n");
   
   char request[REQUEST_BUFFER_SIZE];
   
   int numberServed = 0;
   while (numberServed < NUMBER_OF_PAGES_TO_SERVE) {
      
      printf ("*** So far served %d pages ***\n", numberServed);
      
      int connectionSocket = waitForConnection (serverSocket);
      // wait for a request to be sent from a web browser, open a new
      // connection for this conversation
      
      // read the first line of the request sent by the browser  
      int bytesRead;
      bytesRead = read (connectionSocket, request, (sizeof request)-1);
      assert (bytesRead >= 0); 
      // were we able to read any data from the connection?
            
      // print entire request to the console 
      printf (" *** Received http request ***\n %s\n", request);
      
      //send the browser a simple html page using http
      printf (" *** Sending http response ***\n");
      serveBMP(connectionSocket);
      
      // close the connection after sending the page- keep aust beautiful
      close(connectionSocket);
      
      numberServed++;
   } 
   
   // close the server connection after we are done- keep aust beautiful
   printf ("** shutting down the server **\n");
   close (serverSocket);
   
   return EXIT_SUCCESS; 
}

void serveBMP (int socket) {
   char* message;
   
   // first send the http response header
   
   // (if you write stings one after another like this on separate
   // lines the c compiler kindly joins them togther for you into
   // one long string)
   message = "HTTP/1.0 200 OK\r\n"
                "Content-Type: image/bmp\r\n"
                "\r\n";
   printf ("about to send=> %s\n", message);
   write (socket, message, strlen (message));
   
   // now send the BMP
   unsigned char bmp[] = {
    0x42,0x4d,
     0x36,0x00,0x0C,0x00,
     0x00,0x00,0x00,0x00,
     0x36,0x00,
     0x00,0x00,0x28,0x00,
     0x00,0x00,
     0x00,0x02,0x00,0x00,
     0x00,0x02,0x00,0x00,
     0x01,0x00,0x18,0x00,0x00,0x00,
     0x00,0x00,0x24,0x00,0x00,0x00,0x13,0x0b,
     0x00,0x00,0x13,0x0b,0x00,0x00,0x00,0x00,
     0x00,0x00,0x00,0x00,0x00,0x00};


   write (socket, bmp, sizeof(bmp));
}


// start the server listening on the specified port number
int makeServerSocket (int portNumber) { 
   
   // create socket
   int serverSocket = socket (AF_INET, SOCK_STREAM, 0);
   assert (serverSocket >= 0);   
   // error opening socket
   
   // bind socket to listening port
   struct sockaddr_in serverAddress;
   bzero ((char *) &serverAddress, sizeof (serverAddress));
   
   serverAddress.sin_family      = AF_INET;
   serverAddress.sin_addr.s_addr = INADDR_ANY;
   serverAddress.sin_port        = htons (portNumber);
   
   // let the server start immediately after a previous shutdown
   int optionValue = 1;
   setsockopt (
      serverSocket,
      SOL_SOCKET,
      SO_REUSEADDR,
      &optionValue, 
      sizeof(int)
   );

   int bindSuccess = 
      bind (
         serverSocket, 
         (struct sockaddr *) &serverAddress,
         sizeof (serverAddress)
      );
   
   assert (bindSuccess >= 0);
   // if this assert fails wait a short while to let the operating 
   // system clear the port before trying again
   
   return serverSocket;
}

// wait for a browser to request a connection,
// returns the socket on which the conversation will take place
int waitForConnection (int serverSocket) {
   // listen for a connection
   const int serverMaxBacklog = 10;
   listen (serverSocket, serverMaxBacklog);
   
   // accept the connection
   struct sockaddr_in clientAddress;
   socklen_t clientLen = sizeof (clientAddress);
   int connectionSocket = 
      accept (
         serverSocket, 
         (struct sockaddr *) &clientAddress, 
         &clientLen
      );
   
   assert (connectionSocket >= 0);
   // error on accept
   
   return (connectionSocket);
}

void createbmp () {
// check that the types have the size i'm relying on here
   assert (sizeof(bits8)  == 1);
   assert (sizeof(bits16) == 2);
   assert (sizeof(bits32) == 4);
 
   FILE *outputFile;

 
   outputFile = fopen(BMP_FILE, "wb");
   assert ((outputFile!=NULL) && "Cannot open file");
 
   writeHeader(outputFile);

   //Run tests on escapeSteps function
   // testEscapeSteps();
 
   //Calculate number of bytes we need to send over
   int numBytes = (SIZE * SIZE * BYTES_PER_PIXEL);

   //Next 3 variables hold user inputs
   double inputR = 0;
   double inputI  = 0;
   int zoom = 0;

   //Read in user inputs
   printf("Real part =");
   scanf("%lf", &inputR);
   printf("Imaginary Part =");
   scanf("%lf", &inputI);
   printf("Zoom Level ( >= 0) =");
   scanf("%d", &zoom);
   
   //Counts how many bytes have been sent to BMP file
   int byteCount = 0;

   //Finds starting point for bmp to start printing.
   /* -2*pow(0.5,zoom) ensures co-ords of first pixel printed is found at the 
      bottom left corner of tile*/
   /* (NORM_PIX_SIZE*pow(0.5,zoom) makes sure we test the center of each pixel 
     to see if it is black or white (see lecture on task 2B)*/
   double Re = inputR - 2*pow(0.5, zoom) + (NORM_PIX_SIZE*pow(0.5,zoom));
   double Im = inputI - 2*pow(0.5,zoom) + (NORM_PIX_SIZE*pow(0.5,zoom));

   //Copies starting coords into varibles we can mess around with and then change back into the originals if we need.
   double real = Re;
   double imaginary = Im;

   //Keep looping until we run out of pixels to print into.
   while (byteCount < numBytes){
   
      bits8 byte; 

      //My own grayscale coloring algorithm.  The longer it takes for a value to escape, the whiter it is.
      byte = escapeSteps(real, imaginary);

         write (socket, byte, sizeof(byte));  
         write (socket, byte, sizeof(byte));
         write (socket, byte, sizeof(byte));

      //loads coords of next value to be tested in a line of pixels
      real += (NORM_PIX_SIZE)*pow(0.5,zoom);
     

      if(byteCount%SIZE == 0){

         //If we've started to print a new line of pixels, this alters the coordinates we are working with to it.
         real = Re;

         imaginary += (NORM_PIX_SIZE)*pow(0.5,zoom);

      }

      byteCount++;

   }

      
   fclose(outputFile);
 }

 int escapeSteps(double Re, double Im){


   double RPart = Re;
   double IPart = Im;

   double ReTemp = 0;
   double ImTemp = 0;

   int count = 0;

   int escapeLoop = FALSE;

   /*Means:Keep on looping unless we've looped more than limit
     (255) and we don't want to stop looping. */
   while (count <= ESCAPE_VAL && escapeLoop == FALSE){

      //Check displacement of point from (0,0) on Argand diag.
      double displacementValue = displacement(ReTemp, ImTemp);

      //if displacement of point > 2, stop looping.
      if (displacementValue > 2){

         escapeLoop = TRUE;

      }else{

         //If we haven't stopped looping, load next values.
         RPart = ReTemp;
         IPart = ImTemp;

         ReTemp = (RPart*RPart)-(IPart*IPart)+Re;
         ImTemp = (2*RPart*IPart) + Im;

         count++;

      }

   }

   //Return steps taken to escape loop.
   return count;

}

double displacement(double Real, double Img){

   //Pythag. theorem used to find displacement
   double distance = sqrt(Real*Real+Img*Img);

   return distance;