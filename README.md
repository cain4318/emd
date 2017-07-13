# emd


emdOrigin：  	rubner的原始emd算法，test example1 example2 是测试例子 drawHis 是带画数据柱状图的测试用例
		base on the code released from Rubner Code for the Earth Movers Distance (EMD):http://robotics.stanford.edu/~rubner/emd/default.htm

emd1DTeseter:	实现 论文A Closed-form Gradient for the 1D Earth Mover's Distance for Spectral Deep Learning on Biological Data 
	        中的1D emd 近似算法和近似1D emd的梯度计算算法，（平衡状态，及Supply和Demand 的总量一样多）
	        可以随机生成数据，计算emd距离及梯度，并保存结果
	        batch 可以计算多组随机数据的结果并保存

simpleEMD:      emd性质的测试，比较实验  测试对比rubner的emd 和opencv的emd、测试不同的数据、测试不同的delta（梯度的delta）

dataProcess:    处理二维图像近似推广的emd距离和梯度，自己控制的二维数据测试性质

dataPreProcess：图片预处理之重命名，裁剪，拼接，缩放

alignProcess：  做图像预对准
