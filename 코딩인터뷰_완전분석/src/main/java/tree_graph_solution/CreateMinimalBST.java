package 트리와_그래프_해법;

import javax.swing.tree.TreeNode;

public class CreateMinimalBST {

    public static void main(String[] args) {
        int[] arr = new int[args.length];

        for (int i = 0; i < arr.length; i++){
            arr[i] = Integer.parseInt(args[i]);
        }

        TreeNode root = createMinimalBST(arr, 0, arr.length - 1);

    }

    static TreeNode createMinimalBST(int array[]){
        return createMinimalBST(array, 0, array.length - 1);
    }

    static TreeNode createMinimalBST(int arr[], int start, int end){
        if (end < start){
            return null;
        }

        int mid = (start + end) / 2;
        TreeNode root = new TreeNode(arr[mid]);
        root.left = createMinimalBST(arr, start, mid - 1);
        root.right = createMinimalBST(arr, mid + 1, end);
        return root;
    }
    public static class TreeNode {
        int value;
        TreeNode left;
        TreeNode right;
        boolean visited;

        public TreeNode(int value){
            this.value = value;
        }
    }
}
