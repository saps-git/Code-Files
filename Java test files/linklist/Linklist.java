package linklist;

public class Linklist {
    Node head;

    public Node insert(int data){
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

    public void print(){
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

    public static void main(String[] args) {
        Linklist ll = new Linklist();
        // ll.insert(12);
        // ll.insert(23);
        // ll.insert(45);

        ll.head = ll.insert(0);
        ll.head.next = ll.insert(12);
        ll.head.next.next = ll.insert(23);
        ll.head.next.next.next = ll.insert(45);

        ll.print();

    }
}
