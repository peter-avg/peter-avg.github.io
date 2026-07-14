# Local dev commands for the Jekyll site.
#
# This machine's system Ruby is too old for the gems this project needs,
# but Homebrew's Ruby works — so we point PATH at it here rather than
# relying on the shell's default `ruby`/`bundle`.
RUBY_BIN := /opt/homebrew/opt/ruby/bin
export PATH := $(RUBY_BIN):$(PATH)

PORT ?= 4000
PIDFILE := .jekyll.pid
LOGFILE := .jekyll-serve.log

.PHONY: help install serve view stop build clean

help:
	@echo "make install  - install gems (bundle install)"
	@echo "make serve    - run the dev server in this terminal, live-reloading on save"
	@echo "make view     - run the dev server in the background and open it in your browser"
	@echo "make stop     - stop the background server started by 'make view'"
	@echo "make build    - build the static site into _site/"
	@echo "make clean    - remove build output and caches"

install:
	@bundle check >/dev/null 2>&1 || bundle install

serve: install
	bundle exec jekyll serve --port $(PORT) --livereload

view: install
	@if [ -f $(PIDFILE) ] && kill -0 $$(cat $(PIDFILE)) 2>/dev/null; then \
		echo "Already running (pid $$(cat $(PIDFILE))) at http://127.0.0.1:$(PORT)/"; \
	else \
		bundle exec jekyll serve --port $(PORT) --livereload > $(LOGFILE) 2>&1 & echo $$! > $(PIDFILE); \
		echo "Starting server..."; \
		for i in $$(seq 1 30); do \
			curl -sf http://127.0.0.1:$(PORT)/ >/dev/null && break; \
			sleep 1; \
		done; \
	fi
	@open http://127.0.0.1:$(PORT)/

stop:
	@if [ -f $(PIDFILE) ]; then \
		kill $$(cat $(PIDFILE)) 2>/dev/null || true; \
		rm -f $(PIDFILE); \
		echo "Stopped."; \
	else \
		echo "Not running (no $(PIDFILE))."; \
	fi

build: install
	bundle exec jekyll build

clean:
	rm -rf _site .sass-cache .jekyll-cache .jekyll-metadata $(LOGFILE)
