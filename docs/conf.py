import os

# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

project = 'AspectC++ Library'
copyright = '2025, Bjarne Giesker'
author = 'Bjarne Giesker'
release = '0.1.0'

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

# extensions = [
#          'karma_sphinx_theme'
#      ]

templates_path = ['_templates']
exclude_patterns = ['_build', 'Thumbs.db', '.DS_Store']


# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme_path = ['_themes']
html_static_path = ['_static']

html_theme = "karma-sphinx-theme"
html_logo = '_static/logo.png'
html_context = {
    'style': '',  # oder irgendein Default-Stil, wenn dein Theme das erwartet
}
