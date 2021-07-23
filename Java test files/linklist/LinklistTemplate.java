package linklist;
import java.util.*;

public class LinklistTemplate {
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

    public static void main(String[] args) {
        head = insert(0);
        head.next = insert(1);
        head.next.next = insert(2);
        head.next.next.next = insert(3);
        head.next.next.next.next = insert(4);
        head.next.next.next.next.next = insert(5);
        head.next.next.next.next.next.next = insert(6);
        print();
    }
}


