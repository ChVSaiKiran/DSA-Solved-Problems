class Solution {
    public int numWaterBottles(int numBottles, int numExchange) {
        int drink = numBottles, exchange = numBottles;
        do{
            drink += (exchange / numExchange);
            exchange = (exchange / numExchange) + (exchange % numExchange);
        } while (exchange >= numExchange);
        return drink;
    }
}