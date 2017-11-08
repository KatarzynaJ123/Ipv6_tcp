/*
 ============================================================================
 Name        : projekt.c
 Author      : kasia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>           // close()
#include <string.h>           // strcpy, memset(), and memcpy()
#include <sys/types.h>        // needed for socket(), uint8_t, uint16_t
#include <sys/socket.h>       // needed for socket()
#include <getopt.h>


#define IP6_HDRLEN 40  // IPv6 header length




struct icmp6_hdr{
};


int main (int argc, char **argv){


int c;
int IP_Version = 6;
int Source_IP = 0;
int Destination_IP = 0;
int Payload_length = 0;
int Hop_limit = 32;
int Traffic_class = 0;
int Flow_id =0;
int Next_header=59;
int Number_packets =0;
char *interface;

strcpy (interface, "eth0");


while ((c = getopt (argc, argv, "v:s:d:l:h:t:f:n:i:p:")) != -1)
  switch (c)
    {
    case 'v':
      IP_Version = atoi(optarg);
      break;
    case 's':
      Source_IP = atoi(optarg);
      break;
    case 'd':
    	Destination_IP = atoi(optarg);
    	break;
    case 'l':
    	Payload_length  = atoi(optarg);
    	break;
    case 'h':
    	Hop_limit = atoi(optarg);
    	break;
    case 't':
    	Traffic_class = atoi(optarg);
    	break;
    case 'f':
    	Flow_id  = atoi(optarg);
    	break;
    case 'n':
    	Next_header = atoi(optarg);
    	break;
    case 'p':
       	Number_packets = atoi(optarg);
        break;
    case 'i':
    	interface = optarg;
    	break;

    case '?':
        fprintf (stderr, "Option -%c requires an argument.\n", optopt);

      return 1;
    default:
      abort ();
    }

printf (" IP_Version= %d, Source_IP = %d, Destination_IP = %d,Payload_length = %d,Hop_limit = %d,Traffic_class = %d,Flow_id = %d,Next_header=%d,interface=%s,Number_packets=%d",
		IP_Version, Source_IP,Destination_IP,Payload_length,Hop_limit,Traffic_class,Flow_id,Next_header,interface,Number_packets);
}
