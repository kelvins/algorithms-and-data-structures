class BinaryTreeNode {
    constructor(value, left, right) {
        this.value = value;
        this.left = left;
        this.right = right;
    }
}

class BinarySearchTree {
    constructor() {
        this.root = null;
    }

    add(value) {
        let newNode = new BinaryTreeNode(value, null, null);

        if (this.root == null)
            this.root = newNode;
        else {
            let current = this.root;
            let found = false;

            while (!found) {
                if (newNode.value < current.value) {
                    if (current.left == null) {
                        current.left = newNode;
                        found = true;
                    } else {
                        current = current.left;
                    }

                } else {
                    if (current.right == null) {
                        current.right = newNode;
                        found = true;
                    } else {
                        current = current.right;
                    }
                }
            }
        }
    }

    remove(value) {
        let current = this.root;
        let found = false;

        if (value != this.root.value) {
            let previous = this.root;

            while (current != null && !found) {
                if (value == current.value) {
                    found = true;
                } else if (value < current.value) {
                    previous = current;
                    current = current.left;
                } else {
                    previous = current;
                    current = current.right;
                }
            }

            if (current == null) {
                console.log("Element does not exist");
                return;
            }

            if (current.right == null && current.left == null) {
                if (previous.left == current) previous.left = null;
                else previous.right = null;
            } else if (current.right != null && current.left == null) {
                if (previous.left == current) previous.left = current.right;
                else previous.right = current.right;
            } else if (current.right == null && current.left != null) {
                if (previous.left == current) previous.left = current.left;
                else previous.right = current.left;
            } else {
                let rightNodeOfDeletedElement = current.right;
                let leftNodeOfDeletedElement = current.left;
                let previousOfCurrent;

                if (current == previous.right) {
                    current = current.left;
                    while (current.right != null) {
                        previousOfCurrent = current;
                        current = current.right;
                    }
                    previous.right = current;
                } else {
                    current = current.left;
                    while (current.right != null) {
                        previousOfCurrent = current;
                        current = current.right;
                    }
                    previous.left = current;
                }

                current.right = rightNodeOfDeletedElement;
                current.left = leftNodeOfDeletedElement;
                previousOfCurrent.right = null;
            }
        } else {
            if (current.right == null && current.left == null) {
                this.root = null;
            } else {
                if (current.left != null && current.right == null)
                    this.root = current.left;
                else if (current.left == null && current.right != null)
                    this.root = current.right;
                else if (current.left != null && current.right != null) {
                    let rightNodeOfDeletedElement = this.root.right;
                    let leftNodeOfDeletedElement = this.root.left;
                    let previousOfCurrent;

                    current = this.root.left;
                    while (current.right != null) {
                        previousOfCurrent = current;
                        current = current.right;
                    }
                    this.root = current;

                    current.right = rightNodeOfDeletedElement;
                    current.left = leftNodeOfDeletedElement;
                    previousOfCurrent.right = null;
                }
            }
        }
    }

    containsElement(value) {
        let current = this.root;
        let found = false;

        while (current != null && !found) {
            if (value == current.value) found = true;
            else if (value < current.value) current = current.left;
            else if (value > current.value) current = current.right;
        }

        if (found) console.log("Element Present");
        else console.log("Element Not Found");
    }

    preOrderTraversal(root = this.root) {
        let current = root;

        console.log(current.value);
        if (current.left != null) this.preOrderTraversal(current.left);
        if (current.right != null) this.preOrderTraversal(current.right);
    }

    postOrderTraversal(root = this.root) {
        let current = root;

        if (current.left != null) this.postOrderTraversal(current.left);
        if (current.right != null) this.postOrderTraversal(current.right);
        console.log(current.value);
    }

    inOrderTraversal(root = this.root) {
        let current = root;

        if (current.left != null) this.inOrderTraversal(current.left);
        console.log(current.value);
        if (current.right != null) this.inOrderTraversal(current.right);
    }

    empty() {
        this.root = null;
    }
}

function main() {
  let tree = new BinarySearchTree();

  tree.add(1);
  tree.add(4);
  tree.add(3);
  tree.add(5);
  tree.add(2);

  tree.preOrderTraversal();
  tree.inOrderTraversal();
  tree.postOrderTraversal();

  tree.containsElement(3);
  tree.remove(3);
  tree.containsElement(3);
  tree.inOrderTraversal();

  tree.empty();
  tree.inOrderTraversal();
}

main();

