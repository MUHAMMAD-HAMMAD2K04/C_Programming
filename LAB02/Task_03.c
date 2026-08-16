#include <stdio.h>

int main() {
    float lat_deg, lat_min, lat_sec;
    float lon_deg, lon_min, lon_sec;
    float latitude_decimal, longitude_decimal;

    // Input Latitude
    printf("Enter Latitude (Degrees Minutes Seconds):\n");
    printf("Degrees: ");
    scanf("%f", &lat_deg);
    printf("Minutes: ");
    scanf("%f", &lat_min);
    printf("Seconds: ");
    scanf("%f", &lat_sec);

    // Input Longitude
    printf("\nEnter Longitude (Degrees Minutes Seconds):\n");
    printf("Degrees: ");
    scanf("%f", &lon_deg);
    printf("Minutes: ");
    scanf("%f", &lon_min);
    printf("Seconds: ");
    scanf("%f", &lon_sec);
    

    // Convert Latitude to Decimal
    latitude_decimal = lat_deg + (lat_min / 60.0) + (lat_sec / 3600.0);


    // Convert Longitude to Decimal
    longitude_decimal = lon_deg + (lon_min / 60.0) + (lon_sec / 3600.0);

// Display Decimal Coordinates
    printf("\nDecimal Latitude: %.6f\n", latitude_decimal);
    printf("Decimal Longitude: %.6f\n", longitude_decimal);

    // Check position relative to Equator
    if ((longitude_decimal>50) && (latitude_decimal>50))
     printf("The location is above the Equator.\n");
    else if((longitude_decimal<50) && (latitude_decimal<50))
    printf("The location is below the Equator.\n");  
    else
    printf("The location is exactly on the Equator.\n");

    
    

    return 0;
}
