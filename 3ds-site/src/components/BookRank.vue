<script setup lang="ts">
import { ref } from 'vue'

export interface BookRankProps {
  id: number
  title: string
  author: string
  year: number
  picture: string
  completed_date: Date
  rating: string
}

const props = defineProps<BookRankProps>()

function copyLink() {
  navigator.clipboard.writeText(window.location.host + '#book_' + props.id)
  linkCopied.value = true
}

const linkCopied = ref(false)
</script>

<template>
  <div class="rank-row parent" :id="'book_' + id">
    <hr />
    <h3 class="mobile-title title">{{ title }}</h3>
    <div class="number child">
      <img :src="picture" />
    </div>
    <div class="child info">
      <div class="book">
        <h3 class="desktop-title title">{{ title }}</h3>
        <p>Author: {{ author }}</p>
        <p>Published: {{ year }}</p>
        <p>Completed reading on: {{ completed_date.toLocaleDateString() }}</p>
        <p>Rating: {{ rating }}</p>
      </div>
      <br />
      <div class="review">
        <p class="body">Book is good</p>
      </div>
      <button @click="copyLink()" :disabled="linkCopied">
        {{ linkCopied ? 'Link copied' : 'Copy Link' }}
      </button>
    </div>
  </div>
</template>

<style scoped>
.rank-row {
}

.review .body {
  font-size: 2rem;
}

.rank-row .number {
  font-size: 2rem;
  font-weight: 500;
}

.rank-row .review {
}

.title {
  font-weight: 1000;
}

.rank-row img {
  width: 150px;
  height: auto;
  padding-top: 5px;
  padding-bottom: 5px;
}

.parent {
  padding-top: 1em;
  padding-bottom: 1em;
  text-align: center;
}

@media (min-width: 800px) {
  .child {
    display: inline-block;
    vertical-align: middle;
  }

  .rank-row .info {
    padding-left: 3em;
    width: 400px;
    min-height: 250px;
  }

  .mobile-title {
    display: none;
  }
}

@media (max-width: 800px) {
  .parent {
    max-width: 90%;
    margin: auto;
  }

  .desktop-title {
    display: none;
  }
}

hr {
  max-width: 90%;
  width: 600px;
  color: #ff00ff;
  margin: auto;
}
</style>
