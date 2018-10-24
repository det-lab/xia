# Using Kaitai Struct to Produce Analysis

One of the advantages of using Kaitai Struct to define your data format is the ability to compile the `.ksy` file into the programming language of your choice. This makes it much easier to use the data in question with tools that may already exist in one language or another.

## XIA Example Analysis

The example here is built using binary data courtesy of [XIA](https://www.xia.com/) from the [Pixie-4 Express](https://www.xia.com/dgf_pixie-4e.html) Digital Pulse Processor. The data format was defined using Kaitai Struct in the `ksy/pixie4e.ksy` file and used to generate a Python library to interface with the raw binary file. Finally, the generated Python code was imported into a ipython notebook to demonstrate how analysis could potentially be performed on the raw data. 

The generated code is already included in this repository but instructions for generating the Python library are also shown below. To run the Jupyter Notebook locally, see the instructions under the [Running the IPython Notebook](#running-the-ipython-notebook) section.

## Generating the Python Library

1. The first step is to make sure you have the `kaitai-struct-compiler` installed on your system. The latest version can be found at http://kaitai.io/. To install and use Kaitai Struct you will need to have the Java Development Kit and Java Runtime Environment installed on your machine.

2. Once Kaitai Struct is installed, generating the Python library is easily done using the `pixie4e.ksy` file provided in this repository. From the `xia/` directory execute:

```
> kaitai-struct-compiler -t python ksy/pixie4e.ksy -d src/
```

3. The result should be a new file in the `src/` directory named `pixie4e.py`.

## Running the IPython Notebook

1. In order to run the example Jupyter (ipython) notebook you need to first install a few Python packages. These instructions were developed using the [Anaconda Python 3 distribution](https://www.anaconda.com/download/) and it is highly recommended (if not required) to ensure proper operation. Additionally, I recommend performing (and did) this installation in a [Python virtual environment](https://conda.io/docs/user-guide/tasks/manage-environments.html) in order to maintain a clean native installation on your system. To install the necessary packages run the following commands from you Anaconda Python environment:

    * `conda install matplotlib`
    * `conda install jupyter`
    * `pip install kaitaistruct`

2. Note: if you choose to utilize Anaconda as your Python distribution the above commands should encounter no issues. `matplotlib` and `jupyter` are available via Anaconda's package manager conda (or they may be installed by default). The `kaitaistruct` package is only available using the Python package manager pip.

3. From a terminal or cmd window execute `jupyter notebook`. This should open up a browser window running on localhost. The window should have the directory structure of your filesystem, from there navigate to the `xia/src/` directory that you downloaded from this repository. Click on `xia_analysis.ipynb`. You should now have a jupyter notebook running in your browser window.

4. !!! IMPORTANT !!! Make sure you edit the file path in the first cell to point to the StilbeneAmCs_500_0253.b00 file on your local machine. For example on a Windows machine, the full line of code might look like `pixie_data = Pixie4e.from_file(r"C:\Users\jane_doe\Desktop\xia\data\StilbeneAmCs_500_0253.b00")`

5. To execute the notebook: You may either run all the cells at once by going to the menu bar and selecting `Cell>Run All` or you can execute each cell individually by selecting the desired cell and clicking the `Run` button. If you run each cell individually you must execute them in order to ensure proper operation.

6. You may now make changes and play with the notebook to see what kinds of plots and analysis can be done using the sample data file.