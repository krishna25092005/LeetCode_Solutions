class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        // Ensure start is less than destination for simpler calculation
        if (start > destination) {
            swap(start, destination);
        }
        
        // Calculate the clockwise distance
        int clockwise = 0;
        for (int i = start; i < destination; i++) {
            clockwise += distance[i];
        }
        
        // Calculate the total distance of the circle
        int totalDistance = 0;
        for (int d : distance) {
            totalDistance += d;
        }
        
        // Counterclockwise distance is the total distance minus the clockwise distance
        int counterclockwise = totalDistance - clockwise;
        
        // Return the shorter distance
        return min(clockwise, counterclockwise);
    }
};
