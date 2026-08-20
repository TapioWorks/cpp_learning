import sys
import random
import math

from PyQt5.QtWidgets import (
    QApplication,
    QMainWindow,
    QLabel,
    QWidget,
    QVBoxLayout,
    QPushButton,
)
from PyQt5.QtGui import QIcon, QPixmap, QFont
from PyQt5.QtCore import Qt, QTimer


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("Pulla App v1")
        self.setGeometry(700, 300, 500, 500)
        self.setWindowIcon(QIcon("D:/Memes/sanni/pulla_close_up.png"))

        self.initUI()

        # Timer before jumpscare appears
        self.jumpscare_timer = QTimer()
        self.jumpscare_timer.timeout.connect(self.show_jumpscare)

        self.angry_timer = QTimer()
        self.angry_timer.timeout.connect(self.next_angry_image)

        # Timer for shaking
        self.shake_timer = QTimer()
        self.shake_timer.timeout.connect(self.shake_image)


        # Feed timers
        self.feed_timer = QTimer()
        self.feed_timer.timeout.connect(self.move_food_images)

        self.feed_angle = 0

        self.shake_count = 0


    def initUI(self):
        central_widget = QWidget()
        self.setCentralWidget(central_widget)

        self.layout = QVBoxLayout()
        self.layout.setAlignment(Qt.AlignCenter)


        # Main Pulla image
        self.image = QLabel()

        pixmap = QPixmap("D:/Memes/sanni/pulla_iso.png")
        self.image.setPixmap(pixmap)

        self.image.setScaledContents(True)
        self.image.setFixedSize(250, 250)
        self.image.setAlignment(Qt.AlignCenter)

        self.layout.addWidget(self.image)


        # Text label
        self.text = QLabel("Welcome to Pulla App")
        self.text.setFont(QFont("Arial", 18))
        self.text.setAlignment(Qt.AlignCenter)

        self.layout.addWidget(self.text)


        # Buttons
        self.button1 = QPushButton("Feed Pulla")
        self.button2 = QPushButton("Pet Pulla")
        self.button3 = QPushButton("Angry Pulla")
        self.button4 = QPushButton("Mystery Button")


        self.layout.addWidget(self.button1)
        self.layout.addWidget(self.button2)
        self.layout.addWidget(self.button3)
        self.layout.addWidget(self.button4)


        # Connect buttons
        self.button1.clicked.connect(self.feed_pulla)
        self.button3.clicked.connect(self.start_angry_sequence)
        self.button4.clicked.connect(self.start_jumpscare)


        central_widget.setLayout(self.layout)


    def feed_pulla(self):

        # Hide normal stuff
        self.image.hide()

        self.button1.hide()
        self.button2.hide()
        self.button3.hide()
        self.button4.hide()


        # Rainbow Comic Sans text
        self.feed_text = QLabel("YOU FED PULLA ❤️", self)

        self.feed_text.setFont(
            QFont("Comic Sans MS", 30)
        )

        self.feed_text.setStyleSheet(
            "color: red;"
        )

        self.feed_text.adjustSize()

        self.feed_text.move(
            (self.width() - self.feed_text.width()) // 2,
            (self.height() - self.feed_text.height()) // 2
        )

        self.feed_text.show()


        # Images
        self.food_images = []

        image_paths = [
            "D:/Memes/sanni/pulla.png",
            "D:/Memes/sanni/banana_pulla.png",
            "D:/Memes/sanni/putti.png"
        ]

        for path in image_paths:

            img = QLabel(self)

            img.setPixmap(QPixmap(path))
            img.setScaledContents(True)
            img.resize(80, 80)

            img.show()

            self.food_images.append(img)


        self.feed_angle = 0

        self.feed_timer.start(30)


    def move_food_images(self):

        self.feed_angle += 5

        radius = 150

        center_x = self.width() // 2
        center_y = self.height() // 2


        for i, img in enumerate(self.food_images):

            angle = self.feed_angle + (i * 120)

            x = center_x + math.cos(math.radians(angle)) * radius
            y = center_y + math.sin(math.radians(angle)) * radius


            img.move(
                int(x - 40),
                int(y - 40)
            )


        # Rainbow text effect
        colors = [
            "red",
            "orange",
            "yellow",
            "green",
            "blue",
            "purple"
        ]

        color = colors[
            int(self.feed_angle / 30) % len(colors)
        ]

        self.feed_text.setStyleSheet(
            f"color: {color};"
        )

    def start_angry_sequence(self):

        # Hide normal stuff
        self.image.hide()
        self.text.hide()

        self.button1.hide()
        self.button2.hide()
        self.button3.hide()
        self.button4.hide()


        # Create image holder
        self.angry_image = QLabel(self)

        self.angry_image.setScaledContents(True)
        self.angry_image.resize(300, 300)

        self.angry_image.move(
            (self.width() - 300) // 2,
            (self.height() - 300) // 2
        )

        self.angry_image.show()


        # Start from first image
        self.angry_stage = 0

        self.angry_images = [
            "D:/Memes/sanni/window.jpeg",
            "D:/Memes/sanni/walking_dog.jpg",
            "D:/Memes/sanni/angrydog.jpg"
        ]


        self.angry_timer.start(2000)

    def next_angry_image(self):

        if self.angry_stage < len(self.angry_images):

            pixmap = QPixmap(
                self.angry_images[self.angry_stage]
            )

            self.angry_image.setPixmap(pixmap)

            self.angry_stage += 1

        else:
            self.angry_timer.stop()
            self.close()

    def start_jumpscare(self):
        self.text.setText(
            "Initializing surprise...\n"
            "Please wait..."
        )

        self.button1.hide()
        self.button2.hide()
        self.button3.hide()
        self.button4.hide()

        self.jumpscare_timer.start(7000)


    def show_jumpscare(self):
        self.jumpscare_timer.stop()

        # Hide normal image
        self.image.hide()
        self.text.hide()


        # Create scary image
        self.scary_image = QLabel(self)

        pixmap = QPixmap("D:/Memes/sanni/pulla_close_up.png")

        self.scary_image.setPixmap(pixmap)
        self.scary_image.setScaledContents(True)
        self.scary_image.resize(300, 300)


        self.original_position = self.scary_image.pos()

        self.scary_image.move(
            (self.width() - 300) // 2,
            (self.height() - 300) // 2
        )

        self.scary_image.show()


        # Start shaking
        self.shake_count = 0
        self.original_position = self.scary_image.pos()

        self.shake_timer.start(50)



    def shake_image(self):
        self.shake_count += 1


        x = random.randint(-15, 15)
        y = random.randint(-15, 15)


        self.scary_image.move(
            self.original_position.x() + x,
            self.original_position.y() + y
        )


        # 3 seconds of shaking
        if self.shake_count >= 60:
            self.shake_timer.stop()
            self.close()



def main():
    app = QApplication(sys.argv)

    window = MainWindow()
    window.show()

    sys.exit(app.exec_())


if __name__ == "__main__":
    main()