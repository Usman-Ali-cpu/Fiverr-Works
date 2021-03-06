from random_Art import makeImage
from django.shortcuts import render

import random
import math

from PIL import Image

random.seed()


class X:
    def eval(self, x, y):
        return x

    def __str__(self):
        return "x"


class Y:
    def eval(self, x, y):
        return y

    def __str__(self):
        return "y"


class SinPi:
    def __init__(self, prob):
        self.arg = build(prob * prob)

    def __str__(self):
        return "sin(pi*" + str(self.arg) + ")"

    def eval(self, x, y):
        return math.sin(math.pi * self.arg.eval(x, y))


class CosPi:
    def __init__(self, prob):
        self.arg = build(prob * prob)

    def __str__(self):
        return "cos(pi*" + str(self.arg) + ")"

    def eval(self, x, y):
        return math.cos(math.pi * self.arg.eval(x, y))


class Times:
    def __init__(self, prob):
        self.lhs = build(prob * prob)
        self.rhs = build(prob * prob)

    def __str__(self):
        return str(self.lhs) + "*" + str(self.rhs)

    def eval(self, x, y):
        return self.lhs.eval(x, y) * self.rhs.eval(x, y)


def build(prob=0.99):
    if random.random() < prob:
        return random.choice([SinPi, CosPi, Times])(prob)
    else:
        return random.choice([X, Y])()


def plotIntensity(exp, pixelsPerUnit=150):
    canvasWidth = 2 * pixelsPerUnit + 1
    canvas = Image.new("L", (canvasWidth, canvasWidth))

    for py in range(canvasWidth):
        for px in range(canvasWidth):
            # Convert pixel location to [-1,1] coordinates
            x = float(px - pixelsPerUnit) / pixelsPerUnit
            y = -float(py - pixelsPerUnit) / pixelsPerUnit
            z = exp.eval(x, y)

            # Scale [-1,1] result to [0,255].
            intensity = int(z * 127.5 + 127.5)
            canvas.putpixel((px, py), intensity)

    return canvas


def plotColor(redExp, greenExp, blueExp, pixelsPerUnit=150):
    redPlane = plotIntensity(redExp, pixelsPerUnit)
    greenPlane = plotIntensity(greenExp, pixelsPerUnit)
    bluePlane = plotIntensity(blueExp, pixelsPerUnit)
    return Image.merge("RGB", (redPlane, greenPlane, bluePlane))


def makeImage(numPics=20):
    with open("eqns.txt", 'w') as eqnsFile:
        imagesList = []
        for i in range(numPics):
            redExp = build()
            greenExp = build()
            blueExp = build()

            eqnsFile.write("img" + str(i) + ":\n")
            eqnsFile.write("red = " + str(redExp) + "\n")
            eqnsFile.write("green = " + str(greenExp) + "\n")
            eqnsFile.write("blue = " + str(blueExp) + "\n\n")

            image = plotColor(redExp, greenExp, blueExp)
            imagesList.append(imagesList)
            image.save("img" + str(i) + ".jpg")
    return imagesList


def output(request):
    imglist = []
    imglist = makeImage(20)
    return render(request, {'imgs': imglist})
