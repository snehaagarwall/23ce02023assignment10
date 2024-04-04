#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

// Enumeration for packet type
enum PacketType {
    CONTROL,
    DATA
};

// Union representing packet contents
union Packet {
    struct {
        int opcode;
        int status_code;
    } control_msg;
    char data_payload[MAX_STRING_LENGTH];
};

// Structure representing a data packet
struct DataPacket {
    enum PacketType type;
    union Packet packet;
};

// Function to assign values to control packet
void assignControlPacket(struct DataPacket *packet, int opcode, int status_code) {
    packet->type = CONTROL;
    packet->packet.control_msg.opcode = opcode;
    packet->packet.control_msg.status_code = status_code;
}

// Function to assign values to data packet
void assignDataPacket(struct DataPacket *packet, const char *data) {
    packet->type = DATA;
    strcpy(packet->packet.data_payload, data);
}

// Function to print packet contents
void printPacket(struct DataPacket packet) {
    if (packet.type == CONTROL) {
        printf("Control Packet:\n");
        printf("Opcode: %d\n", packet.packet.control_msg.opcode);
        printf("Status Code: %d\n", packet.packet.control_msg.status_code);
    } else {
        printf("Data Packet:\n");
        printf("Data Payload: %s\n", packet.packet.data_payload);
    }
    printf("\n");
}

int main() {
    // Create an array of DataPacket
    struct DataPacket packets[2];

    // Assign values to demonstrate both control and data packets
    assignControlPacket(&packets[0], 1, 200);
    assignDataPacket(&packets[1], "Hello, world!");

    // Print the packets based on the type
    for (int i = 0; i < 2; i++) {
        printPacket(packets[i]);
    }

    return 0;
}
