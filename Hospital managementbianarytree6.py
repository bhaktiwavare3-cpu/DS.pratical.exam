from collections import deque


# Node class
class Node:
    def __init__(self, patient_id, patient_name):
        self.patient_id = patient_id
        self.patient_name = patient_name
        self.left = None
        self.right = None


# Binary Search Tree class
class BST:

    def __init__(self):
        self.root = None

    # ----------------------------------------
    # 1. INSERTION
    # ----------------------------------------
    def insert(self, patient_id, patient_name):

        new_node = Node(patient_id, patient_name)

        if self.root is None:
            self.root = new_node
            return

        current = self.root

        while True:

            if patient_id < current.patient_id:

                if current.left is None:
                    current.left = new_node
                    return
                else:
                    current = current.left

            elif patient_id > current.patient_id:

                if current.right is None:
                    current.right = new_node
                    return
                else:
                    current = current.right

            else:
                print("Patient ID already exists.")
                return

    # ----------------------------------------
    # 2. SEARCH
    # ----------------------------------------
    def search(self, patient_id):

        current = self.root

        while current is not None:

            if patient_id == current.patient_id:
                return current

            elif patient_id < current.patient_id:
                current = current.left

            else:
                current = current.right

        return None

    # ----------------------------------------
    # 3. DELETE
    # ----------------------------------------
    def delete(self, patient_id):

        self.root = self._delete_node(self.root, patient_id)

    def _delete_node(self, root, patient_id):

        if root is None:
            return root

        # Search in left subtree
        if patient_id < root.patient_id:

            root.left = self._delete_node(
                root.left, patient_id
            )

        # Search in right subtree
        elif patient_id >
