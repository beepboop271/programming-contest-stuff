import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.PriorityQueue;

public class ECOO_20_1_2 {
  public static void main(String[] args) throws NumberFormatException, IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int t = Integer.parseInt(br.readLine());
    String[] line;
    String name;
    ECOO_20_1_2.Item item;
    PriorityQueue<ECOO_20_1_2.Item> pq;
    int quantity, quantityDone;
    int cost;
    int k;
    for (int test = 0; test < t; ++test) {
      // System.out.println("test");
      HashMap<String, PriorityQueue<ECOO_20_1_2.Item>> items = new HashMap<>();
      int n = Integer.parseInt(br.readLine());
      for (int store = 0; store < n; ++store) {
        k = Integer.parseInt(br.readLine());
        for (int order = 0; order < k; ++order) {
          line = br.readLine().split(" ");
          name = line[0];
          item = new ECOO_20_1_2.Item(line[1], line[2]);
          if (items.containsKey(name)) {
            items.get(name).offer(item);
          } else {
            pq = new PriorityQueue<>();
            pq.offer(item);
            items.put(name, pq);
          }
        }
        // System.out.println("store");
      }
      n = Integer.parseInt(br.readLine());
      cost = 0;
      for (int order = 0; order < n; ++order) {
        line = br.readLine().split(" ");
        name = line[0];
        quantity = Integer.parseInt(line[1]);
        quantityDone = 0;
        while (quantityDone < quantity) {
          item = items.get(name).poll();
          cost += item.cost*Math.min(quantity-quantityDone, item.quantity);
          quantityDone += item.quantity;
          // System.out.println(String.format("name = %s, quantity = %d, quantityDone = %d, cost = %d, item.cost = %d, item.quantity = %d\n", name, quantity, quantityDone, cost, item.cost, item.quantity));
        }
      }
      System.out.println(cost);
    }
  }

  public static class Item implements Comparable<ECOO_20_1_2.Item> {
    public int cost;
    public int quantity;
    public Item(String cost, String quantity) {
      this.cost = Integer.parseInt(cost);
      this.quantity = Integer.parseInt(quantity);
    }

    @Override
    public int compareTo(Item o) {
      return this.cost - o.cost;
    }    
  }
}