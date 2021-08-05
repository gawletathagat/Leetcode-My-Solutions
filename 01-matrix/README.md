<h2>542. 01 Matrix</h2><h3>Medium</h3><hr><div><p>Given an <code>m x n</code> binary matrix <code>mat</code>, <gistnote class="gistnote-highlight" highlightid="896ac87d-6cc1-4b91-8f06-96e8504add84" colornum="1" style="background-color: rgb(255, 202, 215);" id="896ac87d-6cc1-4b91-8f06-96e8504add84">return </gistnote><em><gistnote class="gistnote-highlight" highlightid="896ac87d-6cc1-4b91-8f06-96e8504add84" colornum="1" style="background-color: rgb(255, 202, 215);">the distance of the nearest </gistnote></em><code><gistnote class="gistnote-highlight" highlightid="896ac87d-6cc1-4b91-8f06-96e8504add84" colornum="1" style="background-color: rgb(255, 202, 215);">0</gistnote></code><em><gistnote class="gistnote-highlight" highlightid="896ac87d-6cc1-4b91-8f06-96e8504add84" colornum="1" style="background-color: rgb(255, 202, 215);"> for each cell</gistnote></em><gistnote class="gistnote-highlight" highlightid="896ac87d-6cc1-4b91-8f06-96e8504add84" colornum="1" style="background-color: rgb(255, 202, 215);">.</gistnote></p>

<p>The distance between two adjacent cells is <code>1</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/24/01-1-grid.jpg" style="width: 253px; height: 253px;">
<pre><strong>Input:</strong> mat = [[0,0,0],[0,1,0],[0,0,0]]
<strong>Output:</strong> [[0,0,0],[0,1,0],[0,0,0]]
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/24/01-2-grid.jpg" style="width: 253px; height: 253px;">
<pre><strong>Input:</strong> mat = [[0,0,0],[0,1,0],[1,1,1]]
<strong>Output:</strong> [[0,0,0],[0,1,0],[1,2,1]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>4</sup></code></li>
	<li><code>mat[i][j]</code> is either <code>0</code> or <code>1</code>.</li>
	<li>There is at least one <code>0</code> in <code>mat</code>.</li>
</ul>
</div>