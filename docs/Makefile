# Minimal makefile for Sphinx documentation

# You can set these variables from the command line, and also
# from the environment for the first two.
SPHINXOPTS    ?=
SPHINXBUILD   ?= sphinx-build
SOURCEDIR     = .
BUILDDIR      = _build

SCRIPT1 = generate_docs.py
SCRIPT2 = update_index.rst.py

# Put it first so that "make" without argument is like "make help".
help:
	@$(SPHINXBUILD) -M help "$(SOURCEDIR)" "$(BUILDDIR)" $(SPHINXOPTS) $(O)

.PHONY: help Makefile

$(SCRIPT1) :
	python3 $(SCRIPT1)

$(SCRIPT2) :
	python3 $(SCRIPT2)

create_rst: $(SCRIPT1) $(SCRIPT2)

# Define another target that depends on the previous target
show_html: create_rst html
	@echo "Creating HTML files..."
	make build_html
	brave-browser _build/html/index.html

html:
	@$(SPHINXBUILD) -M html "$(SOURCEDIR)" "$(BUILDDIR)" $(SPHINXOPTS) $(O)

clean:
	@$(SPHINXBUILD) -M clean "$(SOURCEDIR)" "$(BUILDDIR)" $(SPHINXOPTS) $(O)

.PHONY: create_rst show_html build_html
