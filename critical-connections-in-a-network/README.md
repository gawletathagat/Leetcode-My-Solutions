<h2>1192. Critical Connections in a Network</h2><h3>Hard</h3><hr><div><p>There are <code>n</code> servers numbered from <code>0</code> to <code>n - 1</code> connected by undirected server-to-server <code><gistnote class="gistnote-highlight" highlightid="dae144a5-025a-4a93-8991-cbb2c23d828c" colornum="1" style="background-color: rgb(255, 202, 215);" id="dae144a5-025a-4a93-8991-cbb2c23d828c">connections</gistnote></code><gistnote class="gistnote-highlight" highlightid="dae144a5-025a-4a93-8991-cbb2c23d828c" colornum="1" style="background-color: rgb(255, 202, 215);"> forming a network where </gistnote><code><gistnote class="gistnote-highlight" highlightid="dae144a5-025a-4a93-8991-cbb2c23d828c" colornum="1" style="background-color: rgb(255, 202, 215);">connections[i] = [a</gistnote><sub><gistnote class="gistnote-highlight" highlightid="dae144a5-025a-4a93-8991-cbb2c23d828c" colornum="1" style="background-color: rgb(255, 202, 215);">i</gistnote></sub><gistnote class="gistnote-highlight" highlightid="dae144a5-025a-4a93-8991-cbb2c23d828c" colornum="1" style="background-color: rgb(255, 202, 215);">, b</gistnote><sub><gistnote class="gistnote-highlight" highlightid="dae144a5-025a-4a93-8991-cbb2c23d828c" colornum="1" style="background-color: rgb(255, 202, 215);">i</gistnote></sub><gistnote class="gistnote-highlight" highlightid="dae144a5-025a-4a93-8991-cbb2c23d828c" colornum="1" style="background-color: rgb(255, 202, 215);">]</gistnote></code><gistnote class="gistnote-highlight" highlightid="dae144a5-025a-4a93-8991-cbb2c23d828c" colornum="1" style="background-color: rgb(255, 202, 215);"> represents a connection between servers </gistnote><code><gistnote class="gistnote-highlight" highlightid="dae144a5-025a-4a93-8991-cbb2c23d828c" colornum="1" style="background-color: rgb(255, 202, 215);">a</gistnote><sub><gistnote class="gistnote-highlight" highlightid="dae144a5-025a-4a93-8991-cbb2c23d828c" colornum="1" style="background-color: rgb(255, 202, 215);">i</gistnote></sub></code><gistnote class="gistnote-highlight" highlightid="dae144a5-025a-4a93-8991-cbb2c23d828c" colornum="1" style="background-color: rgb(255, 202, 215);"> and </gistnote><code><gistnote class="gistnote-highlight" highlightid="dae144a5-025a-4a93-8991-cbb2c23d828c" colornum="1" style="background-color: rgb(255, 202, 215);">b</gistnote><sub><gistnote class="gistnote-highlight" highlightid="dae144a5-025a-4a93-8991-cbb2c23d828c" colornum="1" style="background-color: rgb(255, 202, 215);">i</gistnote></sub></code>. Any server can reach other servers directly or indirectly through the network.</p>

<p>A <em>critical connection</em> is a connection that, if removed, will make some servers unable to reach some other server.</p>

<p>Return all critical connections in the network in any order.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/09/03/1537_ex1_2.png" style="width: 198px; height: 248px;">
<pre><strong>Input:</strong> n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
<strong>Output:</strong> [[1,3]]
<strong>Explanation:</strong> [[3,1]] is also accepted.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 2, connections = [[0,1]]
<strong>Output:</strong> [[0,1]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>n - 1 &lt;= connections.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li>There are no repeated connections.</li>
</ul>
</div>