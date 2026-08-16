#include <stdio.h>

int main()
{
    float supplyVoltage, resistance1, resistance2, resistance3;
    float nodeVoltageV2;
    float current_i1, current_i2, current_i3;

    // Taking inputs from the user
    printf("Enter V1 (Supply Voltage): ");
    scanf("%f", &supplyVoltage);

    printf("Enter R1 (Resistance 1): ");
    scanf("%f", &resistance1);

    printf("Enter R2 (Resistance 2): ");
    scanf("%f", &resistance2);

    printf("Enter R3 (Resistance 3): ");
    scanf("%f", &resistance3);

    // Calculate voltage at node V2 using KCL formula
    nodeVoltageV2 = supplyVoltage / (1 + (resistance1/resistance2) + (resistance1/resistance3));

    // Calculate currents through each resistor
    current_i1 = (supplyVoltage - nodeVoltageV2) / resistance1;
    current_i2 = nodeVoltageV2 / resistance2;
    current_i3 = nodeVoltageV2 / resistance3;

    // Output the results
    printf("\nCurrent i1 = %.2f A\n", current_i1);
    printf("Current i2 = %.2f A\n", current_i2);
    printf("Current i3 = %.2f A\n", current_i3);

    return 0;
}
