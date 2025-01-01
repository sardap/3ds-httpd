<script setup lang="ts">
import { ref } from 'vue'
import { useI18n } from 'vue-i18n'
const { t, d } = useI18n({
  messages: {
    en: {
      author: 'Author: {0}',
      published: 'Published: {0}',
      completed: 'Read on: {0}',
      isbn: 'ISBN: {0}',
      rating: 'Rating: {0}',
      review: 'Book is good',
      link_copied: 'Link copied',
      copy_link: 'Copy Link',
    },
    kr: {
      author: '저자: {0}',
      published: '출판: {0}',
      completed: '완독일: {0}',
      isbn: 'ISBN: {0}',
      rating: '평점: {0}',
      review: '책이 좋아요',
      link_copied: '링크 복사됨',
      copy_link: '링크 복사',
    },
  },
})

export interface BookRankProps {
  id: number
  title: string
  author: string
  year: number
  picture: string
  completed_date: Date
  rating: string
  isbn: string
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
        <p>{{ t('isbn', [isbn]) }}</p>
        <p>{{ t('author', [author]) }}</p>
        <p>{{ t('published', [year]) }}</p>
        <p>{{ t('completed', [d(completed_date, 'date')]) }}</p>
        <p>{{ t('rating', [rating]) }}</p>
      </div>
      <br />
      <div class="review">
        <p class="body">{{ t('review') }}</p>
      </div>
      <button @click="copyLink()" :disabled="linkCopied">
        {{ linkCopied ? t('link_copied') : t('copy_link') }}
      </button>
    </div>
  </div>
</template>

<style scoped>
.review .body {
  font-size: 1.3rem;
}

.rank-row .number {
  font-size: 2rem;
  font-weight: 500;
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
