#include <stdio.h>

#define MAX 30

void inputData(int vehicleID[], int speed[], int lane[], int *n) {
    int i;
    printf("Enter number of vehicles (max 30): ");
    scanf("%d", n);

    for(i = 0; i < *n; i++) {
        printf("Vehicle %d ID: ", i+1);
        scanf("%d", &vehicleID[i]);
        printf("Speed: ");
        scanf("%d", &speed[i]);
        printf("Lane (1-4): ");
        scanf("%d", &lane[i]);
    }
}

int countSpeedViolations(int speed[], int n) {
    int i, count = 0;
    for(i = 0; i < n; i++)
        if(speed[i] > 80) count++;
    return count;
}

int countLaneViolations(int vehicleID[], int lane[], int n) {
    int i, count = 0;
    for(i = 0; i < n; i++)
        if(vehicleID[i] % 4 != lane[i]) count++;
    return count;
}

int busiestLane(int laneCount[]) {
    int i, max = laneCount[0], index = 0;
    for(i = 1; i < 4; i++)
        if(laneCount[i] > max) { max = laneCount[i]; index = i; }
    return index + 1;
}

int leastBusyLane(int laneCount[]) {
    int i, min = laneCount[0], index = 0;
    for(i = 1; i < 4; i++)
        if(laneCount[i] < min) { min = laneCount[i]; index = i; }
    return index + 1;
}

void displayReport(int vehicleID[], int speed[], int lane[], int n) {
    int i;
    printf("\nVehID\tSpeed\tLane\tSpeedViolation\tLaneViolation\n");
    for(i = 0; i < n; i++) {
        int sv = speed[i] > 80 ? 1 : 0;
        int lv = (vehicleID[i] % 4 != lane[i]) ? 1 : 0;
        printf("%d\t%d\t%d\t%d\t\t%d\n", vehicleID[i], speed[i], lane[i], sv, lv);
    }
}

int main() {
    int vehicleID[MAX], speed[MAX], lane[MAX];
    int laneCount[4] = {0};
    int n, i;

    inputData(vehicleID, speed, lane, &n);

    for(i = 0; i < n; i++)
        laneCount[lane[i]-1]++;

    printf("\nTotal Speed Violations: %d", countSpeedViolations(speed, n));
    printf("\nTotal Lane Violations: %d", countLaneViolations(vehicleID, lane, n));
    printf("\nBusiest Lane: %d", busiestLane(laneCount));
    printf("\nLeast Busy Lane: %d", leastBusyLane(laneCount));

    printf("\n\n--- TRAFFIC REPORT ---\n");
    displayReport(vehicleID, speed, lane, n);

    return 0;
}
