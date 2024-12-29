import unittest
import cv2
from main import processing


class TestProcessingFunction(unittest.TestCase):
    def test_processing(self):
        # Load a sample image
        image = cv2.imread("image1.jpg")

        # apply the processing function to the image
        processed_image = processing(image)

        # Check if the image is properly resized
        self.assertEqual(processed_image.shape, (220, 220))

        # Check if the processed image is in grayscale
        # Checking if the number of dimensions is 2
        # which indicates a grayscale image
        self.assertNotEqual(processed_image.ndim, 3) 
        self.assertEqual(processed_image.ndim, 2) 

unittest.main()
