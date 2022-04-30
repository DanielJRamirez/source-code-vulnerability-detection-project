# Vulnerability Detection in Source Code Using Machine Learning and Graph Based Representation

The main scope of this project is applying Machine Learning (ML) algoritms on the graph structure of source code, which is extracted in this project based on the Abstract Syntax Tree (AST) of source code. We propose two approaches for learning graph embeddings of source code in the context of suitable classification to distinguish vulnerable and non-vulnerable code samples. The first approach is based on graph2vec that represents an entire graph as a fixed length feature vector. Based on this representation, classical ML models such as a Support Vector Machine (SVM) and a Multi-Layer Perceptron (MLP) are applied as classifiers.  The second approach is based on the use of Graph Neural Networks (GNNs), which can be applied directly to graphs, and provide an end-to-end capability for node-, edge- and graph-level embedding and prediction.

# Prerequisites
1. Anaconda 4.10.1
2. python 3.8.10
3. Clang : libclang 12.0.0 
4. PyTorch (>=1.4.0)
5. PyTorch Geometric (>=1.4.2)
6. Download graph2vec from: https://github.com/benedekrozemberczki/graph2vec


# Structure
![This is an image](https://github.com/ferasalnaem/Master-thesis/blob/main/ProjectPipeline.png)
         
1) Data Preprocessing: [Data_preprocessing.ipynb](https://github.com/ferasalnaem/Master-thesis/blob/main/Data_preprocessing.ipynb)

* The Draper dataset can be downloaded from : https://osf.io/d45bw/ to the [./Dataset/](https://github.com/ferasalnaem/Master-thesis/tree/main/Dataset) directory.

* Exploring the Draper dataset, preparing data frames, then applying under-sampling to generate balanced subsets.

* The generated balanced subsets should be saved in [./Dataset/](https://github.com/ferasalnaem/Master-thesis/tree/main/Dataset) directory.

2) AST extracting : 
ASTs are extracted using Clang in both approaches.

   The first approach :

    In the following notebook [AST_extracting.ipynb](https://github.com/ferasalnaem/Master-thesis/blob/main/AST_extracting.ipynb), the following steps are performed:
    * Extracting AST from each source code using Clang, which contains features and edges. 
    * Saving each graph in a json file under ./graph2vec/dataset/graph2vec_input (first download the graph2vec model), to be processed later using graph2vec.
    * To see how an extracted AST of a source code looks like, see [clang_example.ipynb](https://github.com/ferasalnaem/Master-thesis/blob/main/clang_example.ipynb).

   The second approach:

    Extracting ASTs in the second approach is done in [GNN_experiments.ipynb](https://github.com/ferasalnaem/Master-thesis/blob/main/GNN_experiments.ipynb).
    In this approach ASTs are extracted and a graph-dataset is built on Pytorch Geometric.

3) Graph- Embedding & Classification: 

   1. The first approach:
    - The first one is based on using graph2v2c to generate graph embeddings. 
    To create an embedding of the generated ASTs in the 'graph2vec_input' directory, run the following:
    
                  $ python src/graph2vec.py --input-path dataset/graph2vec_input/ --output-path features/<file_name>.csv
    
     After that, the graph embeddings could be seen in [./graph2vec/features](https://github.com/ferasalnaem/Master-thesis/tree/main/graph2vec/features).

    - Machine Learning classifiers such as SVM and MLP are implemented in [ML_experiments.ipynb](https://github.com/ferasalnaem/Master-thesis/blob/main/ML_experiments.ipynb) to the generated embeddings for each CWE category.

   2. The second approach:

    In [GNN_experiments.ipynb](https://github.com/ferasalnaem/Master-thesis/blob/main/GNN_experiments.ipynb) a GNN model is built for graph embedding and classification


# Results
The obtained learning curves by training MLP and GNN on each CWE category can be seen in the folder [Learning curves](https://github.com/ferasalnaem/Master-thesis/tree/main/Learning%20curves).

The results of evaluating the models regarding the used performance metrics (Accuracy, Precision, Recall and F1-score) as well as losses are collected after each experiment and can be seen in the following file [Results.pdf](https://github.com/ferasalnaem/Master-thesis/blob/main/Results.pdf).
