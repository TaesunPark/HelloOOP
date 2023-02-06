package 트리와_그래프_해법;

import java.util.LinkedList;

public class 노드_사이의_경로 {

    enum State {Unvisited, Visited, visiting;}

    public static void main(String[] args) {
    }

    public boolean search(Graph g, Node start, Node end){
        if (start == end) return true;

        LinkedList<Node> q = new LinkedList<>();

        for (Node u : g.nodes){
            u.state = State.Unvisited;
        }
        start.state = State.visiting;
        q.add(start);
        Node u;
        while (!q.isEmpty()){
            u = q.removeFirst();
            if (u != null){
                for (Node v : u.children){
                    if (v.state == State.Unvisited){
                        if (v == end){
                            return true;
                        } else{
                            v.state = State.visiting;
                            q.add(v);
                        }
                    }
                }
                u.state = State.Visited;
            }
        }
        return false;
    }

    public class Graph{
        public Node[] nodes;
    }

    public class Node{
        public String name;
        public Node[] children;
        public State state;
    }

}
