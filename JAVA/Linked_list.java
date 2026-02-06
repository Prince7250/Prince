// class Node {
//     int data;
//     Node next; 

//     public Node(int data) {
//         this.data = data;
//         next = null;
//     }
// }

// class LinkedList {
//     Node head = null;

//     public void add(int data) {
//         Node newNode = new Node(data);
//         if (head == null) {
//             head = newNode;
//         } else {
//             Node current = head;
//             while (current.next != null) {
//                 current = current.next;
//             }
//             current.next = newNode;
//         }
//     }

//     public void addFirst(int i) {
//         Node newNode = new Node(i);
//         newNode.next = head;
//         head = newNode;
//     }

//     public void printValues() {
//         Node current = head;
//         while (current != null) {
//             System.out.print(current.data + " -> ");
//             current = current.next;
//         }
//         System.out.println("null");
//     }
// }

// class Main {
//     public static void main(String[] args) {
//         LinkedList Mihir = new LinkedList();
//         Mihir.addFirst(67);
//         Mihir.add(10);
//         Mihir.add(20);
//         Mihir.printValues();
//     }
// }



import java.util.Scanner;

class Node {

    int data;
    Node next;

    public Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    Node head = null;

    // Add at end
    public void add(int data) {
        Node newNode = new Node(data);

        if (head == null) {
            head = newNode;
            return;
        }

        Node current = head;
        while (current.next != null) {
            current = current.next;
        }
        current.next = newNode;
    }

    public void addFirst(int data) {
        Node newNode = new Node(data);
        newNode.next = head;
        head = newNode;
    }

    public void delete(int data) {
        if (head == null)
            return;

        if (head.data == data) {
            head = head.next;
            return;
        }

        Node current = head;
        while (current.next != null && current.next.data != data) {
            current = current.next;
        }

        if (current.next != null) {
            current.next = current.next.next;
        }
    }

    public void printValues() {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " -> ");
            current = current.next;
        }
        System.out.println();
    }
}

class Student {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        LinkedList list = new LinkedList();
        System.out.println("Following operations you can do in Linked_list :");
        System.out.println("[1] Add data.");
        System.out.println("[2] AddFirst data.");
        System.out.println("[3] Delete data.");
        System.out.println("[4] Display Data.");
        System.out.println("[5] Exit.");
        while (true) {
        System.out.println("\nChoose you selection...");
        
            int ch = scanner.nextInt();
            switch (ch) {
                case 1: {
                    System.out.println("\nEnter data to add : ");
                    int data = scanner.nextInt();
                    list.add(data);
                    break;
                }

                case 2: {
                    System.out.println("\nEnter data to add First Node : ");
                    int data = scanner.nextInt();
                    list.addFirst(data);
                    break;
                }
                
                case 3: {
                    System.out.println("\nEnter Existing data to delete: ");
                    int data = scanner.nextInt();
                    list.delete(data);
                    break;
                }

                case 4: {
                    System.out.println("\nData is : \n");
                    list.printValues();
                    break;
                }
                 
                case 5: {
                   System.exit(0);
                }

                default: {
                    System.out.println("Invalid Input");
                    break;
                }

            }
        }
    }
}

//Enter data to add sertain positon
//Delate data from any position
//Search data from Existing list
