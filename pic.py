import matplotlib.pyplot as plt
import pandas as pd

# 读取CSV文件
data = pd.read_csv("result.csv", header=None)

# 绘制每个节点的收敛曲线
for i in range(1, len(data.columns)):
    plt.plot(data[0], data[i], label=f"Node {i-1}")

plt.xlabel("Round")
plt.ylabel("Node Value")
plt.title("Gossip Protocol Convergence")
plt.legend()
plt.show()
