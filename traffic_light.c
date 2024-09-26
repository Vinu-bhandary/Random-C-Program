#include <stdio.h>
#include <unistd.h>

#define RED 0
#define GREEN 1
#define YELLOW 2

typedef struct {
    int north_south;
    int east_west;
} TrafficLight;

typedef enum {
    NS_GREEN_EW_RED,
    NS_YELLOW_EW_GREEN,
    NS_RED_EW_GREEN,
    NS_GREEN_EW_YELLOW
} TrafficLightState;

void initializeTrafficLight(TrafficLight *trafficLight) {
    trafficLight->north_south = RED;
    trafficLight->east_west = GREEN;
}

void displayTrafficLightState(TrafficLight trafficLight) {
    printf("North/South: %s, East/West: %s\n",
           (trafficLight.north_south == RED) ? "RED" : (trafficLight.north_south == GREEN) ? "GREEN" : "YELLOW",
           (trafficLight.east_west == RED) ? "RED" : (trafficLight.east_west == GREEN) ? "GREEN" : "YELLOW");
}

void changeTrafficLightState(TrafficLight *trafficLight, TrafficLightState *currentState) {
    switch (*currentState) {
        case NS_GREEN_EW_RED:
            trafficLight->north_south = GREEN;
            trafficLight->east_west = RED;
            *currentState = NS_GREEN_EW_YELLOW;
            break;
        case NS_GREEN_EW_YELLOW:
            trafficLight->north_south = GREEN;
            trafficLight->east_west = YELLOW;
            *currentState = NS_RED_EW_GREEN;
            break;
        case NS_RED_EW_GREEN:
            trafficLight->north_south = RED;
            trafficLight->east_west = GREEN;
            *currentState = NS_YELLOW_EW_GREEN;
            break;
        case NS_YELLOW_EW_GREEN:
            trafficLight->north_south = YELLOW;
            trafficLight->east_west = GREEN;
            *currentState = NS_GREEN_EW_RED;
            break;
        default:
            // Invalid state
            break;
    }
}

int main() {
    TrafficLight trafficLight;
    initializeTrafficLight(&trafficLight);

    TrafficLightState currentState = NS_YELLOW_EW_GREEN;

    for (int i = 0; i < 10; ++i) {
        if((i+1)%2==0)
        {
            printf("Iteration %d:\n", i + 1);
        displayTrafficLightState(trafficLight);

        // Change the traffic light state
        changeTrafficLightState(&trafficLight, &currentState);

        sleep(2);  // Simulate a delay of 2 seconds
        }
        else {
            printf("Iteration %d:\n", i + 1);
        displayTrafficLightState(trafficLight);

        // Change the traffic light state
        changeTrafficLightState(&trafficLight, &currentState);

        sleep(5);  // Simulate a delay of 5 seconds
        }
    }

    return 0;
}
