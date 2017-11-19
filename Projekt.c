#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>           // close()
#include <string.h>           // strcpy, memset(), and memcpy()
#include <sys/types.h>        // needed for socket(), uint8_t, uint16_t
#include <sys/socket.h>       // needed for socket()
#include <getopt.h>
#include <stdint.h>
#include <netinet/in.h>

#define TCP_HDRLEN 20
#define ETH_HDRLEN 14
#define IP6_HDRLEN 40

uint16_t checksum (uint16_t *, int);
uint16_t tcp6_checksum (struct ip6_hdr, struct tcphdr);



struct ip6_hdr{
    unsigned int
        ip6_version : 4,
        ip6_traffic_class : 8,
		ip6_flow_label : 20;
    uint16_t ip6_length;
    uint8_t  ip6_next_header;
    uint8_t  ip6_hop_limit;
    unsigned int ip6_source_address;
    unsigned int ip6_destination_address;

};

struct tcp_hdr{
	uint16_t tcp_source_port,tcp_destination_port ;
	uint32_t tcp_sequence_number;
	uint32_t tcp_ack_number;
	unsigned int
		tcp_data_offset : 4,
		tcp_reserved : 3,
		tcp_flags : 9;

	uint16_t tcp_window_size;
	uint16_t tcp_checksum;
	uint16_t tcp_urgent_pointer;
	unsigned int tcp_options;
};


struct packet{
	struct ip6_hdr a;
	struct tcp_hdr b;
	char data;
};

struct packet *createPacket(){
	struct packet *pakiet = malloc(sizeof(struct packet));
	return pakiet;
};

void pakiet_ipv6_tcp(struct packet *pakiet, unsigned int version,unsigned int traffic_class, unsigned int flow_label, uint16_t length, uint8_t next_header,uint8_t hop_limit, unsigned int source_address, unsigned int destination_address, uint16_t source_port,uint16_t destination_port, uint32_t sequence_number, uint32_t ack_number, unsigned int data_offset, unsigned int reserved, unsigned int flags, uint16_t window_size, uint16_t checksum, uint16_t urgent_pointer, unsigned int options)
{
	pakiet->a.ip6_version = version;
	pakiet->a.ip6_traffic_class = traffic_class;
	pakiet->a.ip6_flow_label = flow_label;
	pakiet->a.ip6_length = htons (TCP_HDRLEN);
	pakiet->a.ip6_next_header = next_header;
	pakiet->a.ip6_hop_limit = hop_limit;
	pakiet->a.ip6_source_address = "2001:db8::214:51ff:fe2f:1556";
	pakiet->a.ip6_destination_address = "2001:db8::214:51ff:fe2f:1556";

	pakiet->b.tcp_source_port =htons (60);
	pakiet->b.tcp_destination_port = htons (80);
	pakiet->b.tcp_sequence_number = htonl (0);
	pakiet->b.tcp_ack_number = htonl (0);
	pakiet->b.tcp_data_offset = TCP_HDRLEN / 4;
	pakiet->b.tcp_reserved = 0;
	pakiet->b.tcp_flags = flags;
	pakiet->b.tcp_window_size = htons (65535);
	pakiet->b.tcp_checksum = tcp_checksum (a, b); // ????
	pakiet->b.tcp_urgent_pointer = htons (0);
	pakiet->b.tcp_options = options;

	// Ethernet frame length = ethernet header (MAC + MAC + ethernet type) + ethernet data (IP header + TCP header)
	//  frame_length = 6 + 6 + 2 + IP6_HDRLEN + TCP_HDRLEN;
};



