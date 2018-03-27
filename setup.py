from setuptools import setup
from distutils.extension import Extension
from Cython.Build import cythonize
from Cython.Distutils import build_ext
import numpy

def readme():
    with open('README.rst') as f:
        return f.read()


setup(name='statr',
      version='0.1.0.dev5',
      description='Trustworthy statistics in Python',
      long_description=readme(),
      classifiers=[
        'Development Status :: 3 - Alpha',
        'License :: OSI Approved :: GNU General Public License v3 or later (GPLv3+)',
        #'Programming Language :: Python :: 3 :: Only',
        #'Programming Language :: Python :: Implementation :: CPython',
        'Intended Audience :: Science/Research',
        'Natural Language :: English',
        'Topic :: Scientific/Engineering :: Mathematics'
      ],
      keywords='statr r statistics',
      url='https://github.com/franiis/statr-python',
      author='Piotr Krzeszewski',
      author_email='krzeszewskipiotr@gmail.com',
      license='GPLv3',
      packages=['statr'],
      install_requires=[
        "numpy>=1.14"
      ],
      ext_modules = [Extension(
          name="statr", 
          sources=["statr/statr.bycython.c"], 
          include_dirs = [numpy.get_include(), "lib/"],
          extra_objects=["lib/libstatr.a"])],
      test_suite='nose.collector',
      tests_require=['nose', 'nose-cover3'],
      include_package_data=True,
      python_requires='>=3, <4',
      zip_safe=False,
      project_urls={
        'Bug Reports': 'https://github.com/franiis/statr-python/issues/',
        'Source': 'https://github.com/franiis/statr-python/'},
      cmdclass = {
        "build_ext": build_ext
      }
)