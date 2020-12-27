void printTree(TreeNode *head) {
	deque<TreeNode *> q;
	TreeNode *curr = head;
	q.push_back(curr);

	while (!q.empty()) {
		curr = q.front();
		q.pop_front();

		cout << curr->val << " ";

		if (curr->left) {
			q.push_back(curr->left);
		}
		if (curr->right) {
			q.push_back(curr->right);
		}
	}
}
