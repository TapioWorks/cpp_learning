import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QLabel, QWidget, QVBoxLayout, QHBoxLayout, QGridLayout
from PyQt5.QtGui import QIcon, QFont, QPixmap
from PyQt5.QtCore import Qt

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Pulla app")
        self.setGeometry(700, 300, 500, 500)
        self.setWindowIcon(QIcon("D:/Memes/sanni/pulla_close_up.png"))
        self.initUi()


    def initUi(self):
        central_widget = QWidget()
        self.setCentralWidget(central_widget)


        #label = QLabel("Pulla balls", self)
        #label.setFont(QFont("Arial", 30))
        #label.setGeometry(0, 0, 500, 100)
        #label.setStyleSheet("color: red;")

        #label.setAlignment(Qt.AlignCenter)

        label = QLabel(self)
        label.setGeometry(0, 0 ,250, 250)

        pixmap = QPixmap("D:/Memes/sanni/pulla_iso.png")
        label.setPixmap(pixmap)

        label.setScaledContents(True)
        label.setGeometry((self.width() - label.width()) // 2,
                          (self.height() - label.height()) // 2, 
                          label.width(),
                          label.height())

def main():
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec_())

if __name__ == "__main__":
    main()