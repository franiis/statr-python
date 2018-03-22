from setuptools import setup
from distutils.extension import Extension
from Cython.Build import cythonize
import numpy

def readme():
    with open('README.rst') as f:
        return f.read()


setup(name='statr',
      version='0.1.0',
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
      url='https://github.com/franiis/statr',
      author='Piotr Krzeszewski',
      author_email='krzeszewskipiotr@gmail.com',
      license='GPLv3',
      packages=['statr'],
      install_requires=[
      ],
      ext_modules = cythonize([Extension("statr", ["statr/statr_pyx.pyx"], include_dirs = [numpy.get_include(), "statr/lib/"])]),
      test_suite='nose.collector',
      tests_require=['nose', 'nose-cover3'],
      include_package_data=True,
      python_requires='>=3, <4',
      zip_safe=False,
      project_urls={  # Optional
        'Bug Reports': 'https://github.com/franiis/statr/issues/',
        'Source': 'https://github.com/franiis/statr/'
    }
)