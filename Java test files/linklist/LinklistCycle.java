package linklist;

public class LinklistCycle {

    static Node head;

    public static Node insert(int data){
        Node toAdd = new Node(data);
        toAdd.next = null;

        if(head == null) head = toAdd;

        else{
            Node temp = head;
            while(temp.next != null) 
                temp = temp.next;

            temp.next = toAdd;
        }

        return toAdd;
    }

    public static void print(){
        Node temp = head.next;
        while(temp != null){
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    static class Node{
        int data;
        Node next;

        public Node(int data){
            this.data = data;
            next = null;
        }
    }

    public static Node checkCycle() {
        Node slow_ptr = head, fast_ptr = head;
        while(fast_ptr != null && fast_ptr.next != null){
            slow_ptr = slow_ptr.next;
            fast_ptr = fast_ptr.next.next;

            if(slow_ptr == fast_ptr){
                slow_ptr = head;
                while(slow_ptr != fast_ptr){
                    slow_ptr = slow_ptr.next;
                    fast_ptr = fast_ptr.next;
                }
                return slow_ptr;
            }
        }

        return null;
    }

    public static void printCycle(Node juncNode) {
        Node temp = juncNode;
        do{
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        while(temp != juncNode);
        System.out.println();
    }
    public static void main(String[] args) {
        head = insert(0);
        head.next = insert(1);
        head.next.next = insert(2);
        head.next.next.next = insert(3);
        head.next.next.next.next = insert(4);
        head.next.next.next.next.next = insert(5);
        head.next.next.next.next.next.next = insert(6);
        head.next.next.next.next.next.next.next = head.next.next.next;
        
        Node juncNode = checkCycle();
        if(juncNode != null)
            printCycle(juncNode);
        else
            System.out.println("No cycle");  
    }
}
